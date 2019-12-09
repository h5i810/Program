// ****************************************************************
// * 题目：在一个二维数组中，每一行都按照从左到右递增的顺序排序，
// *       每一列都按照从上往下递增的顺序排序。请完成一个函数，
// *       输入这样一个二维数组和一个整数，判断数组中是否含有该整数
// *****************************************************************


bool Find(vector<vector<int>> array, int target){
    int rowCount=array.size();
    bool isFound=false;
    if(rowCount<=0)
        return isFound;
    int colCount=array[0].size();
    int i=rowCount-1;
    int j=0;

    while(i>=0&&j<colCount){
        if(target==array[i][j])
            isFound=true;
        else if(target<array[i][j]){
            i--;
            continue;
        }
        else{
            j++;
            continue;
        }
    }
    
    return isFound;
}
