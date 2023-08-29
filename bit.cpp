bool checkb(int mask, int pos){ return (mask >> pos) & 1; }
int flipb(int num, int pos){ return num ^ (1<<pos); }
void setb(int &num, int pos) { num |= (1<<pos); } 
void unsetb(int &num, int pos) { num &= ~(1<<pos); } 
int lastb(int num) { return num & (-num); }