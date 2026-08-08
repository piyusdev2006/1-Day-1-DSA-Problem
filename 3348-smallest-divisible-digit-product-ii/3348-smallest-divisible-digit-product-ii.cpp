class Solution {
public:

    // factor[digit][prime]
    // 0 -> 2
    // 1 -> 3
    // 2 -> 5
    // 3 -> 7

    static constexpr int F[10][4] = {
        {0, 0, 0, 0}, // 0
        {0, 0, 0, 0}, // 1
        {1, 0, 0, 0}, // 2
        {0, 1, 0, 0}, // 3
        {2, 0, 0, 0}, // 4
        {0, 0, 1, 0}, // 5
        {1, 1, 0, 0}, // 6
        {0, 0, 0, 1}, // 7
        {3, 0, 0, 0}, // 8
        {0, 2, 0, 0}  // 9
    };

    int A, B, C, D;

    int SB, SC, SD;

    // dp[a][b][c][d]
    // = minimum digits needed to satisfy
    // 2^a * 3^b * 5^c * 7^d
    vector<unsigned char> dp;


    // -------------------------------------------------------
    // Convert 4D state to 1D
    // -------------------------------------------------------

    inline int id(int a, int b, int c, int d) {
        return (((a * SB + b) * SC + c) * SD + d);
    }


    // -------------------------------------------------------
    // Factorize t
    // -------------------------------------------------------

    bool factorize(long long t) {

        A = B = C = D = 0;

        while (t % 2 == 0) {
            A++;
            t /= 2;
        }

        while (t % 3 == 0) {
            B++;
            t /= 3;
        }

        while (t % 5 == 0) {
            C++;
            t /= 5;
        }

        while (t % 7 == 0) {
            D++;
            t /= 7;
        }

        // Any remaining factor is unsupported.
        return t == 1;
    }


    // -------------------------------------------------------
    // Build minimum-digit DP
    // -------------------------------------------------------

    void buildDP() {

        SB = B + 1;
        SC = C + 1;
        SD = D + 1;

        int totalStates =
            (A + 1) *
            (B + 1) *
            (C + 1) *
            (D + 1);

        const unsigned char INF = 255;

        dp.assign(totalStates, INF);

        // No factors required.
        dp[id(0, 0, 0, 0)] = 0;


        for (int a = 0; a <= A; a++) {

            for (int b = 0; b <= B; b++) {

                for (int c = 0; c <= C; c++) {

                    for (int d = 0; d <= D; d++) {

                        if (a == 0 &&
                            b == 0 &&
                            c == 0 &&
                            d == 0) {
                            continue;
                        }

                        int best = INF;


                        // Digit 1 contributes nothing,
                        // so don't use it in minimum-digit DP.

                        for (int digit = 2;
                             digit <= 9;
                             digit++) {

                            int na = max(
                                0,
                                a - F[digit][0]
                            );

                            int nb = max(
                                0,
                                b - F[digit][1]
                            );

                            int nc = max(
                                0,
                                c - F[digit][2]
                            );

                            int nd = max(
                                0,
                                d - F[digit][3]
                            );


                            // Digit didn't help.
                            if (na == a &&
                                nb == b &&
                                nc == c &&
                                nd == d) {
                                continue;
                            }


                            int prev =
                                dp[id(
                                    na,
                                    nb,
                                    nc,
                                    nd
                                )];


                            if (prev != INF) {

                                best = min(
                                    best,
                                    1 + prev
                                );
                            }
                        }


                        dp[id(a, b, c, d)] = best;
                    }
                }
            }
        }
    }


    // -------------------------------------------------------
    // Is num already valid?
    // -------------------------------------------------------

    bool validNumber(const string& num) {

        int have2 = 0;
        int have3 = 0;
        int have5 = 0;
        int have7 = 0;


        for (char ch : num) {

            int digit = ch - '0';


            // zero-free
            if (digit == 0)
                return false;


            have2 += F[digit][0];
            have3 += F[digit][1];
            have5 += F[digit][2];
            have7 += F[digit][3];
        }


        return
            have2 >= A &&
            have3 >= B &&
            have5 >= C &&
            have7 >= D;
    }


    // -------------------------------------------------------
    // Build smallest suffix of EXACT length
    // -------------------------------------------------------

    string buildSuffix(
        int need2,
        int need3,
        int need5,
        int need7,
        int len
    ) {

        string result;
        result.reserve(len);


        for (int pos = 0;
             pos < len;
             pos++) {

            int slotsLeft =
                len - pos - 1;


            // Try smallest digit first.
            for (int digit = 1;
                 digit <= 9;
                 digit++) {

                int n2 = max(
                    0,
                    need2 - F[digit][0]
                );

                int n3 = max(
                    0,
                    need3 - F[digit][1]
                );

                int n5 = max(
                    0,
                    need5 - F[digit][2]
                );

                int n7 = max(
                    0,
                    need7 - F[digit][3]
                );


                int required =
                    dp[id(
                        n2,
                        n3,
                        n5,
                        n7
                    )];


                // Remaining requirement can fit.
                if (required <= slotsLeft) {

                    result.push_back(
                        char('0' + digit)
                    );

                    need2 = n2;
                    need3 = n3;
                    need5 = n5;
                    need7 = n7;

                    break;
                }
            }
        }


        return result;
    }


    // =======================================================
    // MAIN
    // =======================================================

    string smallestNumber(
        string num,
        long long t
    ) {

        int n = num.size();


        // ---------------------------------------------------
        // 1. Factorize t
        // ---------------------------------------------------

        if (!factorize(t))
            return "-1";


        // ---------------------------------------------------
        // 2. Build DP
        // ---------------------------------------------------

        buildDP();


        // ---------------------------------------------------
        // 3. num itself works
        // ---------------------------------------------------

        if (validNumber(num))
            return num;


        // ---------------------------------------------------
        // 4. Count factors of complete num
        // ---------------------------------------------------

        int have2 = 0;
        int have3 = 0;
        int have5 = 0;
        int have7 = 0;

        int firstZero = n;


        for (int i = 0; i < n; i++) {

            int digit =
                num[i] - '0';


            if (digit == 0) {

                firstZero =
                    min(firstZero, i);

                continue;
            }


            have2 += F[digit][0];
            have3 += F[digit][1];
            have5 += F[digit][2];
            have7 += F[digit][3];
        }


        // ---------------------------------------------------
        // 5. Try same-length answer
        //
        // Right -> Left
        // ---------------------------------------------------

        for (int i = n - 1;
             i >= 0;
             i--) {

            int current =
                num[i] - '0';


            // Remove current digit.
            // Now factors belong to prefix [0 ... i-1].

            if (current != 0) {

                have2 -= F[current][0];
                have3 -= F[current][1];
                have5 -= F[current][2];
                have7 -= F[current][3];
            }


            // Prefix contains zero.
            // Cannot leave it unchanged.
            if (i > firstZero)
                continue;


            // Try smallest digit > current.
            for (int digit = current + 1;
                 digit <= 9;
                 digit++) {

                int got2 =
                    have2 + F[digit][0];

                int got3 =
                    have3 + F[digit][1];

                int got5 =
                    have5 + F[digit][2];

                int got7 =
                    have7 + F[digit][3];


                // Remaining factor requirement.
                int need2 =
                    max(0, A - got2);

                int need3 =
                    max(0, B - got3);

                int need5 =
                    max(0, C - got5);

                int need7 =
                    max(0, D - got7);


                int suffixLength =
                    n - i - 1;


                // Can remaining factors fit?
                int required =
                    dp[id(
                        need2,
                        need3,
                        need5,
                        need7
                    )];


                if (required <= suffixLength) {

                    string answer =
                        num.substr(0, i);


                    answer.push_back(
                        char('0' + digit)
                    );


                    answer += buildSuffix(
                        need2,
                        need3,
                        need5,
                        need7,
                        suffixLength
                    );


                    return answer;
                }
            }
        }


        // ---------------------------------------------------
        // 6. Same length impossible.
        //
        // IMPORTANT:
        //
        // We are NOT restricted to n+1.
        //
        // Minimum possible length is:
        //
        // max(n + 1, minimumDigits)
        // ---------------------------------------------------

        int minimumDigits =
            dp[id(A, B, C, D)];


        if (minimumDigits == 255)
            return "-1";


        int length =
            max(
                n + 1,
                minimumDigits
            );


        // Fill extra positions with 1.
        //
        // 1 is smallest zero-free digit
        // and doesn't change product.

        string answer(
            length - minimumDigits,
            '1'
        );


        // Build smallest factor-producing suffix.
        answer += buildSuffix(
            A,
            B,
            C,
            D,
            minimumDigits
        );


        return answer;
    }
};