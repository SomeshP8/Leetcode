class Solution {
public:
    /*vector<int> twoSum(vector<int> &numbers, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        map<int, int> mapping;
        vector<int> result(2,0);
        int s=numbers.size();
        for(int i=0; i<s; i++){
            if(mapping[target-numbers[i]]>0){
                result[0]=mapping[target-numbers[i]];
                result[1]=i+1;
                break;
            }
            else
            mapping.insert(numbers[i], i+1);
        }
        return result;
    }*/
    vector<int> twoSum(vector<int> &numbers, int target) {
  vector<int> res(2, 0);
  map<int, int> mapDataToIndex;
  int size = numbers.size();

  for (int i = 0; i < size; ++i) {
    int currentValue = numbers[i];
    int differenceValue = target - numbers[i];
    if (mapDataToIndex[differenceValue] > 0) {
       res[0] = mapDataToIndex[differenceValue];
       res[1] = i + 1;
     return res;
   }
   else {
     mapDataToIndex[currentValue] = i + 1;
   }
 }
 return res;
}
};