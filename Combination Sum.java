class Solution {
	List<List<Integer>> result = new ArrayList<>();

	public List<List<Integer>> combinationSum(int[] candidates, int target) {
		backtrack(0, candidates, target, new ArrayList<>());
		return result;    
	}

	private void backtrack(int index, int[] arr, int target, List<Integer> currList) {
		if (target < 0) return;

		if (target == 0) {
			result.add(new ArrayList<>(currList));
			return;
		}

		for (int tmpIndex = index; tmpIndex < arr.length; tmpIndex++) {
			if (target - arr[tmpIndex] < 0) continue;

			currList.add(arr[tmpIndex]);
			backtrack(tmpIndex, arr, target - arr[tmpIndex], currList);
			currList.remove(currList.size() - 1);
		}

	}
}
