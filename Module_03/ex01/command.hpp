#ifndef __COMMAND_HPP__
#define __COMMAND_HPP__

#include <iostream>
#include <map>

//FIXED : Article class should be abstract
int id = 1;

class Article
{
    private:
    Article(){};
        int _id;
        int _quantity;
        std::string _name;
        double _price;
    
    public:
    Article(std::string name, double price) : _id(id++), _name(name), _price(price), _quantity(0){};
    std::string getName() { return _name; };
    int getId() { return _id; };
    void setQuantity(int quantity) { _quantity = quantity;};
    int getQuantity() { return _quantity; };
    double getPrice() { return _price; };
    void setPrice(double price) { _price = price; };
    virtual ~Article() {};
    virtual Article* clone() = 0 ;
};


//CLASS DON'T NEED TOO BE MODIFIED S[O]LID PRINCIPLE IS RESPECTED

class Command
{
    private:
        int _id;
        std::string _orderDate;
        std::string _clientName;
        double _total;
        std::map<int, Article*> _articles;
    
    public:
    int getId() { return _id; };
    std::string getOrderDate() { return _orderDate; };
    std::string getClientName() { return _clientName; };
    
    void addArticle(Article* article, int quantity){
        if (quantity <= 0)
            return;
        _articles[article->getId()] = article;
        _articles[article->getId()]->setQuantity(quantity);
    };
    double get_total_prince()
    {
        double ret = 0;
        std::map<int, Article*>::iterator it;
        for (it = _articles.begin(); it != _articles.end(); it++)
        {
            ret += it->second->getPrice() * it->second->getQuantity();
        }
        return ret;
    }
};


#endif // __COMMAND_HPP__