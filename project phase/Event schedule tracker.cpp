#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>

using namespace std;

// Event class
class Event {
public:
    int eventID;
    string title;
    time_t startTime;
    time_t endTime;
    int priority; // Priority for manual priority queue

    // Constructor to initialize an event
    Event(int id, const string& t, time_t start, time_t end, int p)
        : eventID(id), title(t), startTime(start), endTime(end), priority(p) {}

    // Print event details
    void printEvent() const {
        cout << "Event ID: " << eventID << ", Title: " << title
             << ", Start Time: " << ctime(&startTime)
             << ", End Time: " << ctime(&endTime)
             << ", Priority: " << priority << endl;
    }

    // For comparison in binary search and sorting
    bool operator<(const Event& other) const {
        return eventID < other.eventID;
    }

    bool operator>(const Event& other) const {
        return eventID > other.eventID;
    }

    bool operator==(const Event& other) const {
        return eventID == other.eventID;
    }

    // For comparison in priority queue based on priority
    bool operator<(int p) const {
        return priority < p;
    }

    // Function to check if the title contains a substring (case-insensitive)
    bool containsTitle(const string& searchTitle) const {
        string lowerTitle = title;
        string lowerSearchTitle = searchTitle;
        transform(lowerTitle.begin(), lowerTitle.end(), lowerTitle.begin(), ::tolower);
        transform(lowerSearchTitle.begin(), lowerSearchTitle.end(), lowerSearchTitle.begin(), ::tolower);
        return lowerTitle.find(lowerSearchTitle) != string::npos;
    }
};

// Manual Priority Queue (Min-Heap) to store events by priority
class PriorityQueue {
private:
    vector<Event> heap;

    // Helper function to maintain heap property
    void heapifyUp(int index) {
        while (index > 0 && heap[(index - 1) / 2].priority > heap[index].priority) {
            swap(heap[(index - 1) / 2], heap[index]);
            index = (index - 1) / 2;
        }
    }

    // Helper function to maintain heap property
    void heapifyDown(int index) {
        int size = heap.size();
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int smallest = index;

        if (left < size && heap[left].priority < heap[smallest].priority)
            smallest = left;
        if (right < size && heap[right].priority < heap[smallest].priority)
            smallest = right;
        if (smallest != index) {
            swap(heap[index], heap[smallest]);
            heapifyDown(smallest);
        }
    }

public:
    void push(const Event& event) {
        heap.push_back(event);
        heapifyUp(heap.size() - 1);
    }

    Event pop() {
        if (heap.empty()) return Event(0, "", 0, 0, 0); // Return a dummy event if empty
        Event topEvent = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
        return topEvent;
    }

    bool isEmpty() const {
        return heap.empty();
    }

    int size() const {
        return heap.size();
    }

    // Function to remove event from the queue
    void removeEvent(int eventID) {
        auto it = find_if(heap.begin(), heap.end(), [eventID](const Event& e) {
            return e.eventID == eventID;
        });
        if (it != heap.end()) {
            swap(*it, heap.back());
            heap.pop_back();
            // Reheapify the queue after removal
            heapifyDown(0);
        }
    }
};

// Event Manager class
class EventManager {
private:
    vector<Event> eventList; // Store events in a sorted vector (sorted by event ID)
    PriorityQueue eventQueue; // Manual priority queue to store events by priority

    // Binary search function to search by event ID
    int binarySearch(int eventID) {
        int left = 0;
        int right = eventList.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (eventList[mid].eventID == eventID) {
                return mid; // Event found
            }
            else if (eventList[mid].eventID < eventID) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return -1; // Event not found
    }

    // Conflict detection: Check if the new event overlaps with any existing events
    bool checkConflict(const Event& newEvent) {
        for (const auto& event : eventList) {
            if (newEvent.startTime < event.endTime && newEvent.endTime > event.startTime) {
                return true; // Conflict detected
            }
        }
        return false; // No conflict
    }

public:
    // Add event and maintain the sorted order by event ID
    void addEvent(const Event& event) {
        if (checkConflict(event)) {
            cout << "Conflict detected! Event cannot be added.\n";
        } else {
            eventList.push_back(event);
            sort(eventList.begin(), eventList.end()); // Sort the events by event ID
            eventQueue.push(event); // Add to priority queue based on priority
            cout << "Event added successfully!\n";
        }
    }

    // Remove event by ID (Cancel task)
    void cancelEvent(int eventID) {
        // Find event in the sorted list and remove it
        auto it = find_if(eventList.begin(), eventList.end(), [eventID](const Event& e) {
            return e.eventID == eventID;
        });

        if (it != eventList.end()) {
            eventQueue.removeEvent(eventID); // Remove from priority queue
            eventList.erase(it); // Remove from the event list
            cout << "Event with ID " << eventID << " has been cancelled.\n";
        } else {
            cout << "Event with ID " << eventID << " not found.\n";
        }
    }

    // Search for an event by ID using binary search
    void searchEventByID(int eventID) {
        int index = binarySearch(eventID);
        if (index != -1) {
            cout << "Event found:\n";
            eventList[index].printEvent();
        } else {
            cout << "Event with ID " << eventID << " not found.\n";
        }
    }

    // Search for events by title
    void searchEventByTitle(const string& title) {
        bool found = false;
        cout << "\n--- Events Matching Title: \"" << title << "\" ---\n";
        for (const auto& event : eventList) {
            if (event.containsTitle(title)) {
                event.printEvent();
                found = true;
            }
        }
        if (!found) {
            cout << "No events found with the title containing: " << title << endl;
        }
    }

    // View all events (sorted by event ID)
    void viewEvents() {
        cout << "\n--- Events Sorted by Event ID ---\n";
        for (const auto& event : eventList) {
            event.printEvent();
        }
    }

    // View events by priority (from highest to lowest)
    void viewEventsByPriority() {
        cout << "\n--- Events Sorted by Priority ---\n";
        while (!eventQueue.isEmpty()) {
            Event topEvent = eventQueue.pop();
            topEvent.printEvent();
        }
    }

    // Handle recurring events (simple demonstration of recurrence)
    void handleRecurringEvents(const Event& event, int recurrenceCount) {
        for (int i = 1; i <= recurrenceCount; ++i) {
            time_t newStartTime = event.startTime + i * 24 * 60 * 60; // Recurring daily
            time_t newEndTime = event.endTime + i * 24 * 60 * 60;
            Event newEvent(event.eventID + i, event.title, newStartTime, newEndTime, event.priority);
            addEvent(newEvent);
        }
    }

    // Function to convert date to time_t (from year, month, day, hour, minute)
    time_t convertToTimeT(int year, int month, int day, int hour, int minute) {
        tm tmTime = {};
        tmTime.tm_year = year - 1900;
        tmTime.tm_mon = month - 1;
        tmTime.tm_mday = day;
        tmTime.tm_hour = hour;
        tmTime.tm_min = minute;
        tmTime.tm_sec = 0; // default to 0 seconds
        return mktime(&tmTime); // Converts tm struct to time_t
    }

    // Menu to interact with events
    void eventMenu() {
        int choice, eventID = 1, recurrenceCount;
        string titleSearch;
        while (true) {
            cout << "\n--- Event Scheduler ---\n";
            cout << "1. Add Event\n";
            cout << "2. View All Events\n";
            cout << "3. View Events by Priority\n";
            cout << "4. Search Event by ID\n";
            cout << "5. Search Events by Title\n";
            cout << "6. Handle Recurring Events\n";
            cout << "7. Cancel Event\n"; // New menu option for cancelling events
            cout << "8. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;
            cin.ignore();  // To ignore leftover newline

            switch (choice) {
                case 1: {
                    string title;
                    int year, month, day, hour, minute, priority;
                    cout << "Enter event title: ";
                    getline(cin, title);

                    cout << "Enter event start time (YYYY MM DD HH MM): ";
                    cin >> year >> month >> day >> hour >> minute;
                    time_t startTime = convertToTimeT(year, month, day, hour, minute);

                    cout << "Enter event end time (YYYY MM DD HH MM): ";
                    cin >> year >> month >> day >> hour >> minute;
                    time_t endTime = convertToTimeT(year, month, day, hour, minute);

                    cout << "Enter event priority (1 to 10, where 1 is highest): ";
                    cin >> priority;

                    Event newEvent(eventID++, title, startTime, endTime, priority);
                    addEvent(newEvent);
                    break;
                }
                case 2:
                    viewEvents();
                    break;
                case 3:
                    viewEventsByPriority();
                    break;
                case 4: {
                    int id;
                    cout << "Enter event ID to search: ";
                    cin >> id;
                    searchEventByID(id);
                    break;
                }
                case 5: {
                    cout << "Enter title keyword to search: ";
                    getline(cin, titleSearch);
                    searchEventByTitle(titleSearch);
                    break;
                }
                case 6: {
                    int id;
                    cout << "Enter event ID to create recurring events: ";
                    cin >> id;
                    cout << "Enter number of occurrences for recurrence: ";
                    cin >> recurrenceCount;

                    int index = binarySearch(id);
                    if (index != -1) {
                        handleRecurringEvents(eventList[index], recurrenceCount);
                    } else {
                        cout << "Event with ID " << id << " not found.\n";
                    }
                    break;
                }
                case 7: {  // Cancel Event Option
                    int id;
                    cout << "Enter event ID to cancel: ";
                    cin >> id;
                    cancelEvent(id);
                    break;
                }
                case 8:
                    cout << "Exiting program...\n";
                    return;
                default:
                    cout << "Invalid choice! Please try again.\n";
            }
        }
    }
};

// Main function to run the event manager
int main() {
    EventManager manager;
    int eventID = 1;

    // Sample events data (title, start time, end time, priority)
    struct EventData {
        string title;
        int year, month, day, startHour, startMinute, endHour, endMinute, priority;
    };

    EventData events[] = {
        {"Project Meeting", 2024, 3, 10, 9, 0, 10, 0, 3},
        {"Team Building Exercise", 2024, 3, 11, 14, 0, 15, 0, 5},
        {"Client Call", 2024, 3, 12, 11, 30, 12, 0, 2},
        {"Lunch with CEO", 2024, 3, 13, 16, 0, 17, 0, 1},
        {"Conference Call", 2024, 3, 14, 10, 0, 11, 0, 4},
        {"Project Presentation", 2024, 3, 15, 13, 0, 14, 0, 6},
        {"Morning Standup", 2024, 3, 16, 8, 30, 9, 0, 7},
        {"Design Review", 2024, 3, 17, 15, 0, 16, 0, 8},
        {"Team Sync-Up", 2024, 3, 18, 14, 0, 15, 0, 9},
        {"Networking Lunch", 2024, 3, 19, 12, 30, 13, 0, 10}
    };

    // Loop through the event data and create events
    for (const auto& eventData : events) {
        time_t startTime = manager.convertToTimeT(eventData.year, eventData.month, eventData.day, eventData.startHour, eventData.startMinute);
        time_t endTime = manager.convertToTimeT(eventData.year, eventData.month, eventData.day, eventData.endHour, eventData.endMinute);

        // Create the event using constructor and add it to the manager
        manager.addEvent(Event(eventID++, eventData.title, startTime, endTime, eventData.priority));
    }

    // Start the event manager menu
    manager.eventMenu();

    return 0;
}
