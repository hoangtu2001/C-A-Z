// who: <your name and Mt SAC username goes here>
// what: <the function of this program>
// why: <the name of the lab>
// when: <the due date of this lab.>

#include "bucket.h"

Bucket::Bucket() : Bucket(DEFAULT_SIZE) {}

Bucket::Bucket(const size_t size) : currentSize{size}
{
	items = new double[currentSize];
    itemCount = 0;
}


size_t Bucket::count() const
{
    return itemCount;
}

bool Bucket::isEmpty() const
{
    if(itemCount == 0) return true;
    else return false;
}
 
void Bucket::add(const double item)
{
    
    if(itemCount< currentSize)
    {
        items[itemCount] = item;
        itemCount++;
    }
    else
        resize();
}

double Bucket::remove()
{
    if(!isEmpty())
    {
        itemCount--;
        return items[itemCount];
    }
    else
        throw std::runtime_error("Bucket is empty");
}

bool Bucket::remove(const double item)
{
    for(size_t i = 0; i<itemCount; i++)
    {
        if(items[i] == item)
        {
            items[i] = items[itemCount-1];
            itemCount--;
            return true;
        }
    }
    return false;
}
void Bucket::clear()
{
    itemCount = 0;
}
size_t Bucket::getFrequency(const double item) const
{
    size_t frequency = 0; 
    for(size_t i=0;i<itemCount;i++)
    {
        if(items[i] == item) 
        frequency++;
    }

    return frequency;
}
bool Bucket::contains(const double item) const
{
    for(size_t i=0;i<itemCount;i++)
    {
        if(items[i] == item) 
        return true;
    }
    return false;
}

void Bucket::resize()
{
    size_t newSize = currentSize*SCALING_FACTOR;
    double* newitems = new double[newSize];
    for (size_t i = 0; i<itemCount; i++)
    {
        newitems[i] = items[i];
    }
    delete[] items;
    items = newitems;
    currentSize = newSize;

}