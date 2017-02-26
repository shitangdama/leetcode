public class NumArray {

int[] array;
int size;
public NumArray(int[] nums) {
    int len = nums.length;
    size=1;
    while(size<len)size=size*2;
    array = new int[size*2-1];
    for(int i=0;i<len;i++)array[size-1+i]=nums[i];
    int ind = size*2-2;
    while(ind>0){
        array[ind/2-1]=array[ind]+array[ind-1];
        ind=ind-2;
    }
}

void update(int i, int val) {
    int ind = i+size-1;
    int delta = val - array[ind];
    while(ind>0){
        array[ind]+=delta;
        ind = (ind-1)/2;
    }
    array[0]+=delta;
}

public int sumRange(int i, int j) {
    int sumleft =0;
    int ileft = size-1+i-1, len = i,u=1,bit;
    while(len>0){
        bit = len&1;
        if(bit==1){
            sumleft+= array[(ileft - u +1 )/u];
            ileft = ileft -u;
        }
        u=u*2;
        len = len/2;
    }
    int sumright =0;
    int iright = size-1+j+1;
    len = size - j -1;
    u=1;
    while(len>0){
        bit = len&1;
        if(bit==1){
            sumright+= array[iright/u];
            ileft = ileft +u;
        }
        u=u*2;
        len = len/2;
    }
    return array[0]-sumleft-sumright;
}

}