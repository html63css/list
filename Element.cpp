struct Element
{
public:
	void setDate(int date)
	{
		date_= date;
	}
	int getDate()
	{
		return date_;
	}
private:
	Element(int date)
	{
		next_ = nullptr;
		date_ = date;
	};
	int date_;
	Element *next_;
};