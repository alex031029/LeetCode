// if two rectangles are not overlapping
// rec2 is above or below or on the left side or on the right side of rec1

class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        if(rec1.empty()||rec2.empty())
            return false;
        return !(rec1[2] <= rec2[0] ||   // left
                 rec1[3] <= rec2[1] ||   // bottom
                 rec1[0] >= rec2[2] ||   // right
                 rec1[1] >= rec2[3]);    // up   

    }
};
