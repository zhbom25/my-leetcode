//
// Created by zhaobo on 2022/2/24.
//
/*
 * 将字符串转化为26位的二进制表示，0表示对应字母不存在，1表示对应字母存在，重复的字母也用1表示，
 * 在判断最大长度时，先将这两个字符串对应的二进制数进行与操作，如果结果不为0说明他们有相同字母，
 * 则不操作；结果为0就是不存在相同字母，判断他们的长度的乘积，遍历找到最大的即可。
 */
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxProduct(vector<string>& words) {
        if(words.size()==0) return 0;
        int len=words.size();
        int *arr=new int[len]();
        for(int i=0;i<len;i++){
            int sum=0;
            for(int j=0;j<words[i].size();j++){
                int index=words[i][j]-'a';
                if(((sum>>index)&1)==0) sum=sum+(1<<index);
            }
            arr[i]=sum;
        }
        int maxlen=0;
        for(int i=0;i<len;i++){
            for(int j=i+1;j<len;j++){
                if((arr[i]&arr[j])==0){
                    int plen=words[i].size()*words[j].size();
                    maxlen=max(maxlen,plen);
                }
            }
        }
        return maxlen;
    }
};

int main(int argc, char** argv)
{
    vector<string> words = {"abcw","baz","foo","bar","xtfn","abcdef"};
    shared_ptr<Solution> solution;
    int ret = solution->maxProduct(words);
    cout << "ret : " << ret << endl;
    return 0;
}
