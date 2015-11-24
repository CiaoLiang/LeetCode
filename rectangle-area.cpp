class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
       return (C-A)*(D-B)+(G-E)*(H-F)-max(0,min(C,G)-max(E,A))*max(0,min(D,H)-max(F,B));
    }
};