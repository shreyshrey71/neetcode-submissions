class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) {
            return 0;
        }
        int l=0, r=1, volume=0, validatedVolume=0;
        for(;r<height.size();r++){
            // cout<<l<<" "<<r<<" "<<volume<<" "<<validatedVolume<<"    -------->    ";
            if(height[r]>=height[l]) {
                l=r;
                validatedVolume+=volume;
                volume=0;
            } else {
                volume+= height[l]-height[r];
            }
            // cout<<l<<" "<<r<<" "<<volume<<" "<<validatedVolume<<endl;
        }
        // cout<<"#############################\n";
        r--;
        l=r-1;
        volume=0;
        for(;l>-1;l--){
            // cout<<l<<" "<<r<<" "<<volume<<" "<<validatedVolume<<"    -------->    ";
            if(height[l]>height[r]){
                r=l;
                validatedVolume+=volume;
                volume=0;
            } else{
                volume+=height[r]-height[l];
            }
            // cout<<l<<" "<<r<<" "<<volume<<" "<<validatedVolume<<endl;
        }
        return validatedVolume;
    }
};
