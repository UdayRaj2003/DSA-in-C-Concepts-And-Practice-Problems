
class info {  
public:  
    int count;  
    char ch;  
    info(int count, char ch) {  
        this->count = count;  
        this->ch = ch;  
    }  
};  

class compare {  
public:   
    bool operator()(info* a, info* b) { return a->count < b->count; }  
};  

class Solution {  
public:  
    string reorganizeString(string s) {  
        // Count frequency of each character  
        vector<int> freq(26, 0);  
        for (char ch : s) {  
            freq[ch - 'a']++;  
        }  
        
        // Create priority queue  
        priority_queue<info*, vector<info*>, compare> pq;  
        for (int i = 0; i < 26; i++) {  
            if (freq[i] > 0) {  
                info* temp = new info(freq[i], i + 'a');  
                pq.push(temp);  
            }  
        }  
        
        // If max frequency > (n+1)/2, impossible to reorganize  
        int n = s.length();  
        if (pq.top()->count > (n + 1) / 2) {  
            // Clean up memory  
            while (!pq.empty()) {  
                delete pq.top();  
                pq.pop();  
            }  
            return "";  
        }  
        
        string ans;  
        while (pq.size() > 1) {  
            info* first = pq.top();  
            pq.pop();  
            info* second = pq.top();  
            pq.pop();  
            
            ans.push_back(first->ch);  
            first->count--;  
            ans.push_back(second->ch);  
            second->count--;  
            
            if (first->count > 0) {  
                pq.push(first);  
            } else {  
                delete first;  
            }  
            
            if (second->count > 0) {  
                pq.push(second);  
            } else {  
                delete second;  
            }  
        }  
        
        // Handle last element if exists  
        if (!pq.empty()) {  
            info* last = pq.top();  
            pq.pop();  
            
            ans.push_back(last->ch);  
            last->count--;  
            
            delete last;  
        }  
        
        return ans;  
    }  
};