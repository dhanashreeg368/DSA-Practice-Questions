class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        unordered_map<int,pair<int,char>>Retreive;//this is for accessing healths and directioin O(1)
        int length=positions.size();
        vector<int>stack(length,0);//this is storing positions 
        vector<int>backUp;

        for(int i=0;i<length;i++){
            Retreive[positions[i]]=make_pair(healths[i],directions[i]);
            backUp.push_back(positions[i]);
        }
        sort(positions.begin(),positions.end());
        int track=-1;
        int flag=0;
        for(int i=0;i<length;i++){
            if(track==-1){
                ++track;
                stack[track]=positions[i];
            }
            else if(track >=0 && (Retreive[positions[i]].second == Retreive[stack[track]].second)){
                ++track;
                stack[track]=positions[i];
            }
            else{
                flag=0;
                while(track >= 0 && Retreive[stack[track]].second=='R'){
                    if(Retreive[positions[i]].first < Retreive[stack[track]].first){
                        Retreive[positions[i]].first=0;
                        Retreive[stack[track]].first--;
                        flag=1;
                        break;
                    }
                    else if(Retreive[positions[i]].first > Retreive[stack[track]].first){
                        Retreive[stack[track]].first=0;
                        Retreive[positions[i]].first--;
                        flag=0;
                        track--;
                    }
                    else{
                         Retreive[stack[track]].first=0;
                         Retreive[positions[i]].first=0;
                         flag=1;
                         track--;
                         break;
                    }
                }
                if(flag==0){
                    ++track;
                    stack[track]=positions[i];
                }
            }
        }
        vector<int>Res;
        for(int i=0;i<length;i++){
            if(Retreive[backUp[i]].first > 0){
                Res.push_back(Retreive[backUp[i]].first);
            }
        }
        return Res;
    }
};