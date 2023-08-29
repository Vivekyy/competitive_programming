// True if bit at pos is 1
bool bit(int mask, int pos){
    return (mask >> pos) & 1;
}

int flip(int num, int pos){
    return num ^ (1<<pos);
}