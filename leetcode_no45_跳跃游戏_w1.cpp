﻿/*------------------------------------------------------------------|
给定一个非负整数数组，你最初位于数组的第一个位置。

数组中的每个元素代表你在该位置可以跳跃的最大长度。

你的目标是使用最少的跳跃次数到达数组的最后一个位置。

示例:

输入: [2,3,1,1,4]
输出: 2
解释: 跳到最后一个位置的最小跳跃数是 2。
     从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。
说明:

假设你总是可以到达数组的最后一个位置。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/jump-game-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。|
-------------------------------------------------------------------*/

/*	贪心算法
*
*	执行用时：4 ms, 在所有 C++ 提交中击败了99.70%的用户
*	内存消耗：7.6 MB, 在所有 C++ 提交中击败了74.82%的用户
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>

using namespace std;

int jump(vector<int>& nums) 
{
	int max_pos = 0;
	int end = 0;
	int cnt = 0;

	size_t len = nums.size();

	for (int i = 0; i < len - 1; i++)
	{
		max_pos = max(max_pos, i + nums[i]);		/*	寻找能找到的最远位置	*/

		if (i == end)
		{
			end = max_pos;							/*	把i的终点更新	*/
			cnt++;									/*	计数+1	*/
		}

	}
	return cnt;
}

int main()
{
	vector<int> nums = { 2,3,1,1,4 };


	cout << jump(nums) << endl;
}