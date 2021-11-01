class Solution {
  using BoardTy = vector<vector<char>>;
  enum { B = 'B', X = 'X', O = 'O' };

public:
  void solve(BoardTy &Board) {
    unsigned M = Board.size();
    unsigned N = Board[0].size();
    if (M <= 2 || N <= 2)
      return;

    static const function<void(int, int)> markBorder = [&](int I, int J) {
      if (I < 0 || I >= Board.size() || J < 0 || J >= Board[0].size() ||
          Board[I][J] != O)
        return;

      Board[I][J] = B;
      markBorder(I + 1, J);
      markBorder(I - 1, J);
      markBorder(I, J + 1);
      markBorder(I, J - 1);
    };

    for (unsigned I = 0; I < M; ++I) {
      markBorder(I, 0);
      markBorder(I, N - 1);
    }

    for (unsigned J = 0; J < N; ++J) {
      markBorder(0, J);
      markBorder(M - 1, J);
    }

    for (unsigned I = 0; I < M; ++I) {
      for (unsigned J = 0; J < N; ++J) {
        char C = Board[I][J];
        if (C != X)
          Board[I][J] = C == O ? X : O;
      }
    }
  }
};