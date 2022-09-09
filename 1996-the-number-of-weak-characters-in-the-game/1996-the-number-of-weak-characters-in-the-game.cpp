class Solution {
public:
	int numberOfWeakCharacters(vector<vector<int>>& properties) {
		if (properties.size() < 2)
			return 0;
		sort(properties.begin(), properties.end(), [](
			vector<int> &f,
			vector<int> &s
			) {
			return f[0] == s[0] ? f[1] < s[1] : f[0] < s[0];
		});
		int count = 0;
		auto
			max = properties.rbegin(),
			end = properties.rend(),
			head = max;
		while (head != end && (*head)[0] == (*max)[0])
			++head;
		decltype(max) neck, last_max;
		while (max != end) {
			last_max = max;
			// find next max
			max = head;
			while (max != end && (*max)[1] < (*last_max)[1])
				++max;

			count += max - head;

			// find neck of max
			neck = max;
			while (neck != end && (*neck)[0] == (*max)[0] && (*neck)[1] >= (*last_max)[1])
				++neck;

			// find head of max
			head = neck;
			while (head != end && (*head)[0] == (*max)[0])
				++head;

			count += head - neck;
		}
		return count;
	}
};