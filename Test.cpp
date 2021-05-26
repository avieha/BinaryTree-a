#include "doctest.h"
#include "BinaryTree.hpp"
#include <string>
using namespace ariel;
using namespace std;

template <typename T>
void build_tree(BinaryTree<T> &b)
{
    b.add_root(0).add_left(0, 1).add_right(0, 2).add_left(1, 3).add_right(1, 4).add_left(2, 5).add_right(2, 6).add_left(3, 7).add_right(3, 8).add_left(4, 9).add_right(5, 10).add_left(6, 11).add_right(6, 12);
}

void build_tree(BinaryTree<string> &b)
{
    b.add_root("0").add_left("0", "1").add_right("0", "2").add_left("1", "3").add_right("1", "4").add_left("2", "5").add_right("2", "6").add_left("3", "7").add_right("3", "8").add_left("4", "9").add_right("5", "10").add_left("6", "11").add_right("6", "12");
}


TEST_CASE("pre-order traversal")
{
    SUBCASE("int tree")
    {
        BinaryTree<int> t;
        CHECK_THROWS(t.add_left(0, 1));
        CHECK_THROWS(t.add_right(0, 1));
        t.add_root(0);
        CHECK_NOTHROW(t.add_left(0, 1));
        t.add_root(1);
        CHECK_THROWS(t.add_left(0, 1));
        build_tree(t);
        string result = "";
        string expeted = "0 1 3 7 8 4 9 2 5 10 6 11 12";
        for (auto itr = t.begin_preorder(); itr != t.end_preorder(); itr++)
        {
            result += to_string(*itr) + " ";
        }
        CHECK_EQ(result, expeted);
    }

    SUBCASE("double tree")
    {
        BinaryTree<double> t;
        CHECK_THROWS(t.add_left(0, 1));
        CHECK_THROWS(t.add_right(0, 1));
        t.add_root(0);
        CHECK_NOTHROW(t.add_left(0, 1));
        t.add_root(1);
        CHECK_THROWS(t.add_left(0, 1));
        build_tree(t);
        string result = "";
        string expeted = "0 1 3 7 8 4 9 2 5 10 6 11 12";
        for (auto itr = t.begin_preorder(); itr != t.end_preorder(); itr++)
        {
            result += to_string(*itr) + " ";
        }
        CHECK_EQ(result, expeted);
    }

    SUBCASE("string tree")
    {
        BinaryTree<string> t;
        CHECK_THROWS(t.add_left("0", "1"));
        CHECK_THROWS(t.add_right("0", "1"));
        t.add_root("0");
        CHECK_NOTHROW(t.add_left("0", "1"));
        t.add_root("1");
        CHECK_THROWS(t.add_left("0", "1"));
        build_tree(t);
        string result = "";
        string expeted = "0 1 3 7 8 4 9 2 5 10 6 11 12";
        for (auto itr = t.begin_preorder(); itr != t.end_preorder(); itr++)
        {
            result += *itr + " ";
        }
        CHECK_EQ(result, expeted);
    }
}

TEST_CASE("in-order traversal")
{
    SUBCASE("int tree")
    {
        BinaryTree<int> t;
        CHECK_THROWS(t.add_left(0, 1));
        CHECK_THROWS(t.add_right(0, 1));
        t.add_root(0);
        CHECK_NOTHROW(t.add_left(0, 1));
        t.add_root(1);
        CHECK_THROWS(t.add_left(0, 1));
        build_tree(t);
        string result = "";
        string expeted = "7 3 8 1 9 4 0 5 10 2 11 6 12";
        for (auto itr = t.begin_preorder(); itr != t.end_preorder(); itr++)
        {
            result += to_string(*itr) + " ";
        }
        CHECK_EQ(result, expeted);
    }

    SUBCASE("double tree")
    {

        BinaryTree<double> t;
        CHECK_THROWS(t.add_left(0, 1));
        CHECK_THROWS(t.add_right(0, 1));
        t.add_root(0);
        CHECK_NOTHROW(t.add_left(0, 1));
        t.add_root(1);
        CHECK_THROWS(t.add_left(0, 1));
        build_tree(t);
        string result = "";
        string expeted = "7 3 8 1 9 4 0 5 10 2 11 6 12";
        for (auto itr = t.begin_preorder(); itr != t.end_preorder(); itr++)
        {
            result += to_string(*itr) + " ";
        }
        CHECK_EQ(result, expeted);
    }

    SUBCASE("string tree")
    {
        BinaryTree<string> t;
        CHECK_THROWS(t.add_left("0", "1"));
        CHECK_THROWS(t.add_right("0", "1"));
        t.add_root("0");
        CHECK_NOTHROW(t.add_left("0", "1"));
        t.add_root("1");
        CHECK_THROWS(t.add_left("0", "1"));
        build_tree(t);
        string result = "";
        string expeted = "7 3 8 1 9 4 0 5 10 2 11 6 12";
        for (auto itr = t.begin_preorder(); itr != t.end_preorder(); itr++)
        {
            result += *itr + " ";
        }
        CHECK_EQ(result, expeted);
    }
}


TEST_CASE("post-order traversal")
{
    SUBCASE("int tree")
    {
        BinaryTree<double> t;
        CHECK_THROWS(t.add_left(0, 1));
        CHECK_THROWS(t.add_right(0, 1));
        t.add_root(0);
        CHECK_NOTHROW(t.add_left(0, 1));
        t.add_root(1);
        CHECK_THROWS(t.add_left(0, 1));
        build_tree(t);
        string result = "";
        string expeted = "7 8 3 9 4 1 10 5 11 12 6 2 0";
        for (auto itr = t.begin_preorder(); itr != t.end_preorder(); itr++)
        {
            result += to_string(*itr) + " ";
        }
        CHECK_EQ(result, expeted);
    }

    SUBCASE("double tree")
    {

        BinaryTree<double> t;
        CHECK_THROWS(t.add_left(0, 1));
        CHECK_THROWS(t.add_right(0, 1));
        t.add_root(0);
        CHECK_NOTHROW(t.add_left(0, 1));
        t.add_root(1);
        CHECK_THROWS(t.add_left(0, 1));
        build_tree(t);
        string result = "";
        string expeted = "7 8 3 9 4 1 10 5 11 12 6 2 0";
        for (auto itr = t.begin_preorder(); itr != t.end_preorder(); itr++)
        {
            result += to_string(*itr) + " ";
        }
        CHECK_EQ(result, expeted);
    }

    SUBCASE("string tree")
    {
        BinaryTree<string> t;
        CHECK_THROWS(t.add_left("0", "1"));
        CHECK_THROWS(t.add_right("0", "1"));
        t.add_root("0");
        CHECK_NOTHROW(t.add_left("0", "1"));
        t.add_root("1");
        CHECK_THROWS(t.add_left("0", "1"));
        build_tree(t);
        string result = "";
        string expeted = "7 8 3 9 4 1 10 5 11 12 6 2 0";
        for (auto itr = t.begin_preorder(); itr != t.end_preorder(); itr++)
        {
            result += *itr + " ";
        }
        CHECK_EQ(result, expeted);
    }
}