#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target)
{
	vector<int> retVec;
	vector<int> iVec = nums;
	int nStart = 0, nEnd = 0;
	int nSize = nums.size();
	int nSum = 0;
	int i = 0, nFlag1 = 0, nFlag2 = 0;
	
	if (nSize <= 0)
		return retVec;
		
	sort(iVec.begin(), iVec.end());
	nStart = 0, nEnd = nSize - 1;
	
	while ((nStart < nEnd) && ((nSum = iVec[nStart] + iVec[nEnd]) != target))
	{
		if (nSum > target)
			--nEnd;
		else
			++nStart;
	}
	
	if (nStart == nEnd)
		return retVec;
		
	for (i = 0; i < nSize; ++i)    
	{
		if (!nFlag1 && (nums[i] == iVec[nStart]))
		{
			retVec.push_back(i+1);
			nFlag1 = 1;
			continue;
		}
		
		if (!nFlag2 && (nums[i] == iVec[nEnd]))
		{
			retVec.push_back(i+1);
			nFlag2 = 1;
		}
		
		if (nFlag1 && nFlag2)
			break;
	}
	
	if (retVec[0] > retVec[1])
	{
		retVec[0] = retVec[0] + retVec[1];
		retVec[1] = retVec[0] - retVec[1];
		retVec[0] = retVec[0] - retVec[1];
	}
	
	return retVec;
}

void print(vector<int> iVec)
{
	for (int i = 0; i < iVec.size(); ++i)
		cout << iVec[i] << " ";
	
	cout << endl;
}

int main(void)
{
	int a[] = {3, 2, 4};
	int target = 6;

	int nSize = sizeof(a) / sizeof(int);
	vector<int> nums(a, a+nSize);
	vector<int> ret;	
	
	cout << "raw data:";
	print(nums);

	ret = twoSum(nums, target);
	cout << "target:" << target << "\t" << "two nums' index:";
	print(ret);

	return 1;
}
