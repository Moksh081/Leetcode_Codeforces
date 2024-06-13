class Solution {
public:
    int minMovesToSeat(std::vector<int>& seats, std::vector<int>& students) {
        // Sort both the seats and students vectors
        std::sort(seats.begin(), seats.end());
        std::sort(students.begin(), students.end());

        int totalMoves = 0;
        int n = seats.size();

        // Calculate the total number of moves required
        for (int i = 0; i < n; ++i) {
            totalMoves += std::abs(seats[i] - students[i]);
        }

        return totalMoves;
    }
};
