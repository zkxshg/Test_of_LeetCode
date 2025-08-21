// Design + queue
class AuthenticationManager {
public:
    queue<string> idList;
    map<string, int> timeL;
    int ttl = 0;
    
    AuthenticationManager(int timeToLive) {
        idList = queue<string>(); timeL.clear();
        ttl = timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        while (!idList.empty() && timeL[idList.front()] + ttl <= currentTime) idList.pop();
        
        idList.push(tokenId);
        timeL[tokenId] = currentTime;
    }
    
    void renew(string tokenId, int currentTime) {
        while (!idList.empty() && timeL[idList.front()] + ttl <= currentTime) idList.pop();
        
        queue<string> q2; bool get = false;
        while (!idList.empty()) {
            if (idList.front() != tokenId) q2.push(idList.front());
            else get = true;
            
            idList.pop();
        }
        
        idList = q2;
        
        if (get) {
            idList.push(tokenId);
            timeL[tokenId] = currentTime;
        }
    }
    
    int countUnexpiredTokens(int currentTime) {
        while (!idList.empty() && timeL[idList.front()] + ttl <= currentTime) idList.pop();
        
        return idList.size();
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */
