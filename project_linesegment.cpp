
#include <iostream>
#include <tuple>
#include <vector>
using namespace std;
typedef tuple<int, int, int, int> Line;
typedef pair<int, int> Pair;


Pair* seperate_line_to_pair(Line line) {
    Pair two_point[2];
    int x1 = get<0>(line), y1 = get<1>(line), x2 = get<2>(line), y2 = get<3>(line);
    two_point[0] = { x1,y1 };
    two_point[1] = { x2,y2 };
    return two_point;
}

long double where_point_located_of_line(Pair point, Line line) {
    long double x1 = get<0>(line), y1 = get<1>(line), x2 = get<2>(line), y2 = get<3>(line);
    long double p_x = point.first, p_y = point.second;
    //cout << "(y2 - y1) / (x2 - x1) * (p_x - x1) + y1 - p_y: " << (y2 - y1) / (x2 - x1) * (p_x - x1) + y1 - p_y << endl;
    return (y2 - y1) / (x2 - x1) * (p_x - x1) + y1 - p_y;
}

bool isCrossed(Line l1, Line l2) {
    int x1 = get<0>(l1), y1 = get<1>(l1), x2 = get<2>(l1), y2 = get<3>(l1);
    int x3 = get<0>(l2), y3 = get<1>(l2), x4 = get<2>(l2), y4 = get<3>(l2);

    Pair* first_two_point = seperate_line_to_pair(l1);
    Pair p1 = first_two_point[0];
    Pair p2 = first_two_point[1];
    Pair* second_two_point = seperate_line_to_pair(l2);
    Pair p3 = second_two_point[0];
    Pair p4 = second_two_point[1];

    cout << where_point_located_of_line(p1, l2) * where_point_located_of_line(p2, l2) << " " <<
        where_point_located_of_line(p3, l1) * where_point_located_of_line(p4, l1) << endl;

    return ((where_point_located_of_line(p1, l2) * where_point_located_of_line(p2, l2) <= 0) &&
        (where_point_located_of_line(p3, l1) * where_point_located_of_line(p4, l1) <= 0));
}

int main()
{
    int count_loop;
    cin >> count_loop;
    vector<Line> line_list;
    vector<vector<Line>> line_divided_by_group;

    for (int i = 0; i < count_loop; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        Line line = { x1,y1,x2,y2 };
        line_list.push_back(line);
    }

    while (!line_list.empty()) {
        Line temp_line = line_list.back();
        bool isadded = false;
        if (line_divided_by_group.empty()) {
            vector<Line> vec;
            vec.push_back(temp_line);
            line_divided_by_group.push_back(vec);
        }
        else {
            for (int j = 0; j < line_divided_by_group.size(); j++) {
                for (int k = 0; k < line_divided_by_group[j].size(); k++) {
                    if (isCrossed(line_divided_by_group[j][k], temp_line)) {
                        isadded = true;
                        line_divided_by_group[j].push_back(temp_line);
                        break;
                    }
                }

            }
            if (!isadded) {
                vector<Line>temp;
                temp.push_back(temp_line);
                line_divided_by_group.push_back(temp);
            }

        }
        line_list.pop_back();
    }
    int max = 0;
    for (int j = 0; j < line_divided_by_group.size(); j++) {
        int count = line_divided_by_group[j].size();
        if (max < count)max = count;
        cout << j + 1 << "번째 그룹의 개수는 " << count << endl;
    }
    cout << "max count는 " << max << endl;
}