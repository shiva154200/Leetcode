class Solution {
    public:
        int numRescueBoats(vector<int>& people, int limit) {
                sort(people.begin(),people.end());
                        int n=people.size();
                                int c=0;
                                        int i=0;
                                                int j=n-1;
                                                        while(i<=j){
                                                                  if(people[i]+people[j]<=limit) i++;
                                                                            j--;
                                                                                      c++;
                                                                                              }
                                                                                                      return c;
                                                                                                          }
                                                                                                          };
