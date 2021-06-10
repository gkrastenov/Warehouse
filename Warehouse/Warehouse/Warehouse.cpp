#include <iostream>
#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"

#include "HomeView.h"

TEST_CASE("String")
{
	String myStr("test");
	CHECK(myStr.getLength() == 4);
	CHECK(myStr.isEmpty() == false);
	String other("test2");
	myStr.swap(other);
	CHECK(myStr == "test2");
	myStr.push_back('k');
	CHECK(myStr.getLength() == 6);
	CHECK(myStr == "test2k");
}

TEST_CASE("List")
{
	List<int> list;
	CHECK(list.getSize() == 0);
	list.add(5);
	list.add(2);
	CHECK(list.getSize() == 2);
}

TEST_CASE("DateTime")
{
	DateTime time1("2021/5/1");
	CHECK(time1.getDay() != 0);
	CHECK(time1.getMonth() != 0);
	CHECK(time1.getYear() != 0);

	DateTime time2("2021/6/10");
	CHECK(time1.getDay() != 0);
	CHECK(time1.getMonth() != 0);
	CHECK(time1.getYear() != 0);

	// operators:
	CHECK(time1 < time2);
	CHECK(time1 <= time2);
	CHECK(time1 != time2);
	CHECK((time1 == time2) == false);
}

TEST_CASE("FileView")
{
	FileView view;

	Product product;
	String string("test");
	product.setDescription(string);
	product.setManufacturer(string);
	product.setComment(string);
	product.setQuantity(4);
	product.setLocation(4);

	DateTime time1("2021/5/1");
	product.setEntryDate(time1);
	product.setExpiryDate(time1);

	CHECK(view.isValidEnterFileName("other") == false);
	CHECK(view.isValidEnterComment(product));
	CHECK(view.isValidEnterManufacturer(product));
	CHECK(view.isValidEnterComment(product));
	CHECK(view.isValidEnterQuantity(product));
	CHECK(view.isValidEnterLocation(product));
	CHECK(view.isValidEnterDate(time1));
}

int main()
{
	doctest::Context().run();

	HomeView view = HomeView();

	while (true)
	{
		if (view.menu() == false)
		{
			break;
		}
	}
}