<<<<<<< HEAD
 public int hIndex(int[] citations) {
   Arrays.sort(citations);
   int len=citations.length;
    for(int i=0;i<len;i++){
        if(citations[i]>=len-i) return len-i;

    }
    return 0;
=======
 public int hIndex(int[] citations) {
   Arrays.sort(citations);
   int len=citations.length;
    for(int i=0;i<len;i++){
        if(citations[i]>=len-i) return len-i;

    }
    return 0;
>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74
}