#pragma once
class Score {
private:
	double study_Score;//60%
	double daily_Score;//24%
	double per_Score;//2��
	double inter_Score;//14%
	
public:
	double sum_Score;
	//���캯��
	Score() {}
	Score(double s1, double s2, double s3, double s4);
	//get�ຯ��
	double get_sum_Score();
	double get_study_Score();
	double get_daily_Score();
	double get_per_Score();
	double get_inter_Score();
	//set�ຯ��
	void set_sum_Score(double score);
	void set_study_Score(double score);
	void set_daily_Score(double score);
	void set_per_Score(double score);
	void set_inter_Score(double score);
	~Score() {}
};