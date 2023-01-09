class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
      int totalPetrol = 0;
      int totalDistance = 0;
      for(int i=0;i<n;i++) {
          totalPetrol += p[i].petrol;
          totalDistance += p[i].distance;
      }
      if(totalPetrol < totalDistance) {
          return -1;
      }
       int index = 0;
       int fuel = 0;
       for(int i=0;i<n;i++) {
           fuel += p[i].petrol - p[i].distance;
           
           if(fuel < 0) {
               fuel = 0;
               index = i+1;
           }
       }
       return index;
    }
};