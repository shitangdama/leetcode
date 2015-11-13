public List<Integer> majorityElement(int[] nums) {
    List<Integer> result=new ArrayList<Integer>();
    int y = 0, z = 1, cy = 0, cz = 0;
    for (int x: nums) {
      if (x==y) 
        cy++;
      else if (x==z) 
        cz++;
      else if (cy==0){
          y=x; 
          cy=1;
      }else if (cz==0){
          z=x; 
          cz=1;
      }else{ 
          cy--;
          cz--;
      }
    }
    cy = cz = 0;
    for (int x: nums){
      if (x==y) 
        cy++;
      else if (x== z) 
        cz++;
    }
    if (cy>nums.length/3) 
        result.add(y);
    if (cz>nums.length/3) 
        result.add(z);
    return result;
}