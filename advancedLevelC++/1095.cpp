#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

struct Record {
	Record () {
		second = 0;
		valid = false;
	}
	string plate_number, time, status;
	int second;
	bool valid;
};

bool cmp(Record a, Record b) {
	return a.second < b.second;
}

int trans_second(string time) {
	string h, m, s;
	h = time.substr(0, 2);
	m = time.substr(3, 2);
	s = time.substr(6, 2);
	return stoi(s) + stoi(m)*60 + stoi(h)*3600;
} 

int n, k, cur_index = 0, max_period = 0;
vector<Record> records;
vector<string> plate_numbers;
map<string, int> in_time, car_idx, in_period;

void check_query(string query) {
	int second = trans_second(query);
	while (cur_index < n && records[cur_index].second <= second) {
		Record r = records[cur_index];
		if (r.valid && r.status == "in") {
			in_time[r.plate_number] = r.second;
		} else if (r.valid && r.status == "out"){
			in_period[r.plate_number] += r.second - in_time[r.plate_number];
			if (in_period[r.plate_number] > max_period) {
				max_period = in_period[r.plate_number];
				plate_numbers.clear();
				plate_numbers.push_back(r.plate_number);
			} else if (in_period[r.plate_number] == max_period) {
				plate_numbers.push_back(r.plate_number);
			}
			in_time.erase(r.plate_number);
		}
		cur_index++;
	}
}

int main () {
	scanf("%d %d", &n, &k);
	for (int i=0; i<n; i++) {
		Record record;
		cin >> record.plate_number >> record.time >> record.status;
		record.second = trans_second(record.time);
		if (in_period.count(record.plate_number) == 0)
			in_period[record.plate_number] = 0;
		records.push_back(record);
	}
	sort(records.begin(), records.end(), cmp);
	map<string, int> in_index;
	for (int i=0; i<records.size(); i++) {
		Record r = records[i];
		if (r.status == "in") {
			in_index[r.plate_number] = i;	
		} else {
			if (in_index.count(r.plate_number) > 0) {
				records[in_index[r.plate_number]].valid = true;
				records[i].valid = true;
				in_index.erase(r.plate_number);
			}	
		}
	}
	for (int i=0; i<k; i++) {
		string query;
		cin >> query;
		check_query(query);
		printf("%d\n", in_time.size());
	}
	check_query("23:59:59");
	sort(plate_numbers.begin(), plate_numbers.end());
	for (int i=0; i<plate_numbers.size(); i++) {
		printf("%s ", plate_numbers[i].c_str());
	}
	int hour = (max_period - max_period%3600)/3600;
	int min = (max_period - hour*3600)/60;
	int sec = max_period - hour*3600 - min*60;
	printf("%02d:%02d:%02d\n", hour, min, sec);
	return 0;
}
