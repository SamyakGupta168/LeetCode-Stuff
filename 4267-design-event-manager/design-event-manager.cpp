class EventManager {
public:
    unordered_set<int> activeEvents;
    map<int,set<int>> list;
    unordered_map<int,int> priority;
    
    EventManager(vector<vector<int>>& events) {
        for(auto &v : events) {
            activeEvents.insert(v[0]);
            list[v[1]].insert(v[0]);
            priority[v[0]] = v[1];
        }
    }
    
    void updatePriority(int eventId, int newPriority) {
        if(activeEvents.count(eventId)) {
            int oldPriority = priority[eventId];
            list[oldPriority].erase(eventId);
            if(list[oldPriority].size()==0) list.erase(oldPriority);
            priority[eventId] = newPriority;
            list[newPriority].insert(eventId);
        }
    }
    
    int pollHighest() {
        if(activeEvents.size()==0) return -1;
        auto it = list.rbegin();
        int highestPriority = it->first;
        int lowestId = *list[highestPriority].begin();
        list[highestPriority].erase(lowestId);
        if(list[highestPriority].size()==0) list.erase(highestPriority);
        priority.erase(lowestId);
        activeEvents.erase(lowestId);
        return lowestId;
    }
};

/**
 * Your EventManager object will be instantiated and called as such:
 * EventManager* obj = new EventManager(events);
 * obj->updatePriority(eventId,newPriority);
 * int param_2 = obj->pollHighest();
 */