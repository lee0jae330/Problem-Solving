#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int penalty, last, ce, cscore, format;

string startDate, startTime;

int N, M, S;

unordered_set<string> member_set;

class Problem {
   public:
    int id, order, pscore;

    Problem() {}

    Problem(int i, int o, int p) {
        id = i;
        order = o;
        pscore = p;
    }
};

class UserProblem {
   public:
    int score, goodSubmissionId, tryCount, totalTryCount, lastCorrectSubmissionId, lastSubmissionId;
    string correctDate, correctTime;
    UserProblem() {}
    UserProblem(int s, int g, int t, int total, int lCSId, int lSId, string d, string tm) {
        score = s;
        goodSubmissionId = g;
        tryCount = t;
        totalTryCount = total;
        lastCorrectSubmissionId = lCSId;
        lastSubmissionId = lSId;
        correctDate = d;
        correctTime = tm;
    }

    void print() {
        cout << score << ' ' << goodSubmissionId << ' ' << tryCount << ' ' << totalTryCount << ' ' << lastCorrectSubmissionId << ' ' << lastSubmissionId << ' ' << correctDate << ' ' << correctTime
             << '\n';
    }
};

class User {
   public:
    ll totalScore, penalty;
    int lastCorrectSubmissionId, lastSubmissionId;
    string id;
    // 문제 order, 문제id,  score, 시도 횟수, 패널티
    vector<tuple<int, int, int, int, ll>> history;
    User() {}
    User(ll t, ll p, int lCSId, int lSId, string i, vector<tuple<int, int, int, int, ll>> v) {
        totalScore = t;
        penalty = p;
        lastCorrectSubmissionId = lCSId;
        lastSubmissionId = lSId;
        id = i;
        history = v;
    }
};

tuple<int, int, int> parseyyyyMMdd(string date) { return {stoi(date.substr(0, 4)), stoi(date.substr(5, 2)), stoi(date.substr(8))}; }

bool isLeap(int year) { return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0; }

int getEndDate(int year, int month) {
    switch (month) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 31;
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
        default:
            if (isLeap(year)) return 29;
            return 28;
    }
}

int getDaysDifferenceBetweenStartEnd(string start, string end) {
    int startYear, startMonth, startDay, endYear, endMonth, endDay;
    tie(startYear, startMonth, startDay) = parseyyyyMMdd(start);
    tie(endYear, endMonth, endDay) = parseyyyyMMdd(end);

    int cnt = 0;
    while (!(startYear == endYear && startMonth == endMonth && startDay == endDay)) {
        if (startMonth == 12) {
            // 12월일 때
            if (startDay == getEndDate(startYear, startMonth)) {
                // 12월의 마지막날이면
                startYear++;
                startMonth = 1;
                startDay = 1;
            } else {
                startDay++;
            }
        } else {
            // 12월이 아니고
            if (startDay == getEndDate(startYear, startMonth)) {
                startMonth++;
                // 현재 월의 마지막 날일 때
                startDay = 1;
            } else {
                startDay++;
            }
        }
        cnt++;
    }

    return cnt - 1;
}

int getSecondsDifferenceBetweenStartEnd(string startTime, string endTime) {
    int startTotalTime = stoi(startTime.substr(0, 2)) * 60 * 60 + stoi(startTime.substr(3, 2)) * 60 + stoi(startTime.substr(6));
    int correctTotalTime = stoi(endTime.substr(0, 2)) * 60 * 60 + stoi(endTime.substr(3, 2)) * 60 + stoi(endTime.substr(6));

    return correctTotalTime - startTotalTime;
}

unordered_map<int, Problem> problem_map;
unordered_map<string, unordered_map<int, UserProblem>> user_log;
vector<User> ranking;

bool compRanking(const User& a, const User& b) {
    if (a.totalScore == b.totalScore) {
        if (a.penalty == b.penalty) {
            if (a.lastCorrectSubmissionId == b.lastCorrectSubmissionId) {
                if (a.lastSubmissionId == b.lastSubmissionId) {
                    return a.id < b.id;
                }
                return a.lastSubmissionId < b.lastSubmissionId;
            }
            return a.lastCorrectSubmissionId < b.lastCorrectSubmissionId;
        }
        return a.penalty < b.penalty;
    }
    return a.totalScore > b.totalScore;
}

bool compProblem(const tuple<int, int, int, int, ll>& a, const tuple<int, int, int, int, ll>& b) {
    int x1, x2, y1, y2, z1, z2, id1, id2;
    ll i1, i2;
    tie(x1, id1, y1, z1, i1) = a;
    tie(x2, id2, y2, z2, i2) = b;
    return x1 < x2;
}

string convertToHHmm(ll penalty) {
    ll h = penalty / 60;
    ll m = penalty % 60;

    string str = to_string(h) + ":" + (m < 10 ? "0" + to_string(m) : to_string(m));
    return str;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> penalty >> startDate >> startTime >> last >> ce >> cscore >> format;

    cin >> N;

    for (int i = 0; i < N; i++) {
        int id, order, pscore;
        cin >> id >> order >> pscore;

        problem_map[id] = Problem(id, order, pscore);
    }

    cin >> M;

    for (int i = 0; i < M; i++) {
        string m_id;
        cin >> m_id;
        member_set.insert(m_id);

        unordered_map<int, UserProblem> tmp;
        for (auto iter = problem_map.begin(); iter != problem_map.end(); iter++) {
            tmp[iter->first] = UserProblem(0, 0, 0, 0, 0, 0, "", "");
        }
        user_log[m_id] = tmp;
    }

    cin >> S;

    for (int i = 0; i < S; i++) {
        int sid, pid, result, presult, score;
        string uid, dDate, dTime;

        cin >> sid >> pid >> uid >> result >> presult >> score >> dDate >> dTime;

        if (member_set.find(uid) == member_set.end()) {
            continue;
        }

        // 컴파일 에러 제외 시 무시 or result = 13 없는 제출 무시
        if (ce && result == 11 || result == 13) {
            continue;
        }

        unordered_map<int, UserProblem>& currentlog = user_log[uid];

        UserProblem& currentProblem = currentlog[pid];
        currentProblem.totalTryCount++;  // 전체 시도횟수 증가

        // 제출 결과 : 성공 or 부분 성공
        if (result == 4) {
            if (!presult) {
                // 성공
                int adjustedScore = cscore ? score ? score : problem_map[pid].pscore : 1;
                if (!currentProblem.goodSubmissionId || currentProblem.score < adjustedScore) {
                    // 좋은 제출이 없거나, 좋은 제출이 있지만 현재 얻은 점수보다 높은 점수일 때
                    currentProblem.score = adjustedScore;                    // 점수 대회면 제출 점수, 일반 대회 1점
                    currentProblem.goodSubmissionId = sid;                   // 좋은 제출 갱신
                    currentProblem.tryCount = currentProblem.totalTryCount;  // 좋은 제출까지의 시도횟수 갱신
                    currentProblem.lastCorrectSubmissionId = sid;            // 마지막으로 맞은 제출번호 갱신
                    currentProblem.lastSubmissionId = sid;                   // 마지막으로 제출한 제출번호 갱신
                    currentProblem.correctDate = dDate;                      // 시간 갱신
                    currentProblem.correctTime = dTime;
                } else if (currentProblem.score >= adjustedScore) {
                    // 좋은 제출이 있지만 현재 얻은 점수가 더 높을 때
                    currentProblem.lastCorrectSubmissionId = sid;  // 마지막으로 맞은 제출번호 갱신
                    currentProblem.lastSubmissionId = sid;         // 마지막으로 제출한 제출번호 갱신
                }

            } else {
                // 부분 성공
                if (!cscore) {
                    // 일반 대회인 경우, 부분 성공은 틀린 것임
                    goto failed;
                }

                int adjustedScore = cscore ? score : 1;
                if (!currentProblem.goodSubmissionId || currentProblem.score < adjustedScore) {
                    // 좋은 제출이 없거나, 좋은 제출이 있지만 현재 얻은 점수보다 높은 점수일 때
                    currentProblem.score = adjustedScore;                    // 점수 대회면 제출 점수, 일반 대회 1점
                    currentProblem.goodSubmissionId = sid;                   // 좋은 제출 갱신
                    currentProblem.tryCount = currentProblem.totalTryCount;  // 시도횟수 증가
                    currentProblem.lastCorrectSubmissionId = sid;            // 마지막으로 맞은 제출번호 갱신
                    currentProblem.lastSubmissionId = sid;                   // 마지막으로 제출한 제출번호 갱신
                    currentProblem.correctDate = dDate;                      // 시간 갱신
                    currentProblem.correctTime = dTime;
                } else if (currentProblem.score >= adjustedScore) {
                    // 좋은 제출이 있지만 현재 얻은 점수가 더 높을 때
                    currentProblem.lastCorrectSubmissionId = sid;  // 마지막으로 맞은 제출번호 갱신
                    currentProblem.lastSubmissionId = sid;         // 마지막으로 제출한 제출번호 갱신
                }
            }
            continue;
        }

    failed:
        // 성공, 부분 성공 이외의 제출이면, 마지막 제출 id만 갱신
        currentProblem.lastSubmissionId = sid;
    }

    // for (auto i : user_log) {
    //     cout << quoted(i.first) << '\n';
    //     for (auto j : i.second) {
    //         cout << j.first << ' ';
    //         j.second.print();
    //     }
    //     cout << '\n';
    // }

    for (auto i : user_log) {
        string uId = i.first;
        ll totalScore = 0;
        int lastCorrectSubmissionId = 0, lastSubmissionId = 0;
        ll totalPenalty = 0;

        ll totalPenalty1 = 0;
        ll totalPenalty2 = 0;

        vector<tuple<int, int, int, int, ll>> v;

        for (auto problem : i.second) {
            int pId = problem.first;
            UserProblem up = problem.second;
            totalScore += up.score;
            lastCorrectSubmissionId = max(lastCorrectSubmissionId, up.lastCorrectSubmissionId);
            lastSubmissionId = max(lastSubmissionId, up.lastSubmissionId);

            // 좋은 제출이 없는 경우, 틀린 문제거나 안푼 문제
            if (!up.goodSubmissionId) {
                // 문제 order, 획득 점수, 총 시도 횟수, 패널티 = 0
                v.emplace_back(problem_map[pId].order, pId, up.score, up.totalTryCount, (ll)0);
            } else {
                // 좋은 제출이 있는 경우
                // 패널티를 계산해야함
                ll penalty1, penalty2;
                if (startDate == up.correctDate) {
                    // 대회 시작 날짜와 맞은 날짜가 같은 경우
                    int seconds = getSecondsDifferenceBetweenStartEnd(startTime, up.correctTime);

                    penalty1 = (up.tryCount - 1) * penalty;  // 패널티1, 좋은 제출 전까지 유저 u가 문제 p에 제출한 횟수 * 대회 페널티

                    penalty2 = seconds / 60;  // 패널티2, 좋은 제출이 제출되기까지 소요된 시간 (분)

                } else {
                    // 대회 시작 날짜와 맞은 날짜가 다른 경우,

                    ll differenceDays = getDaysDifferenceBetweenStartEnd(startDate, up.correctDate);
                    ll seconds1 = getSecondsDifferenceBetweenStartEnd(startTime, "24:00:00");
                    ll seconds2 = getSecondsDifferenceBetweenStartEnd("00:00:00", up.correctTime);

                    penalty1 = (up.tryCount - 1) * penalty;  // 패널티1, 좋은 제출 전까지 유저 u가 문제 p에 제출한 횟수 * 대회 페널티

                    penalty2 = differenceDays * 24 * 60 * 60 + seconds1 + seconds2;

                    penalty2 /= 60;
                }
                v.emplace_back(problem_map[pId].order, pId, up.score, up.tryCount, last ? penalty2 : penalty1 + penalty2);

                totalPenalty1 += penalty1;

                if (!last) {
                    // 마지막 패널티 사용하지 않는 경우
                    totalPenalty2 += penalty2;
                } else {
                    // 마지막 패널티 사용 시 가장 큰 penalty2
                    totalPenalty2 = max(totalPenalty2, penalty2);
                }
            }
        }
        // User(ll t, ll p, int lCSId, int lSId, string i, vector<tuple<int, int, int, ll>> v) {
        sort(v.begin(), v.end(), compProblem);
        ranking.push_back(User(totalScore, totalPenalty1 + totalPenalty2, lastCorrectSubmissionId, lastSubmissionId, uId, v));
    }

    sort(ranking.begin(), ranking.end(), compRanking);

    int len = ranking.size();

    // for (User u : ranking) {
    //     cout << u.id << ' ' << u.lastCorrectSubmissionId << ' ' << u.lastSubmissionId << ' ' << u.totalScore << ' ' << u.penalty << '\n';
    // }

    for (int i = 0; i < len; i++) {
        int r = 0;
        for (int j = 0; j < i; j++) {
            if (ranking[j].totalScore > ranking[i].totalScore || ranking[j].totalScore == ranking[i].totalScore && ranking[j].penalty < ranking[i].penalty) {
                r++;
            }
        }
        cout << r + 1 << ',';
        User u = ranking[i];
        cout << u.id << ",";

        int sz = u.history.size();

        for (int j = 0; j < sz; j++) {
            auto [o, pId, score, tryCount, userPenalty] = u.history[j];
            if (!cscore) {
                // 일반대회
                if (score) {
                    cout << "a/" << tryCount << '/';
                    if (format) {
                        cout << convertToHHmm(userPenalty);
                    } else {
                        cout << userPenalty;
                    }
                } else if (tryCount) {
                    cout << "w/" << tryCount << '/' << "--";
                } else {
                    cout << "0/--";
                }
            } else {
                // 점수대회
                if (problem_map[pId].pscore == score) {
                    // 문제 배점과 획득 점수가 동일한 경우
                    cout << "a/" << score << '/' << tryCount << '/';
                    if (format) {
                        cout << convertToHHmm(userPenalty);
                    } else {
                        cout << userPenalty;
                    }
                } else if (score) {
                    cout << "p/" << score << '/' << tryCount << '/';
                    if (format) {
                        cout << convertToHHmm(userPenalty);
                    } else {
                        cout << userPenalty;
                    }

                } else if (tryCount) {
                    cout << "w/" << tryCount << '/' << "--";
                } else {
                    cout << "0/--";
                }
            }

            cout << ',';
        }
        cout << u.totalScore << '/';
        if (format) {
            cout << convertToHHmm(u.penalty);
        } else {
            cout << u.penalty;
        }
        cout << '\n';
    }

    return 0;
}