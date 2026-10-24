class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
      vector<int>daysinmonths={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
if(leaveAlice<arriveBob||leaveBob<arriveAlice) return 0;
string st= (arriveAlice<=arriveBob)?arriveBob:arriveAlice;
string end= (leaveAlice<=leaveBob)?leaveAlice:leaveBob;

cout<<st<<" "<<end;

if(st.substr(0,2)==end.substr(0,2))
return stoi(end.substr(3,2))-stoi(st.substr(3,2))+1;

int days=daysinmonths[stoi(st.substr(0,2))-1]-stoi(st.substr(3,2))+1;


int month=stoi(st.substr(0,2))+1;
int lstmonth=stoi(end.substr(0,2));

// cout<<month<<" "<<lstmonth;

while(month<lstmonth) {days+=daysinmonths[month-1];
month++;}

days+=stoi(end.substr(3,2));

return days;
     
    }
};