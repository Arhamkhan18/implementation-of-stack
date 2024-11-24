#include <iostream>
#include <vector>
#include <algorithm>

class IndirectArray {
public:
    IndirectArray(int size) : size(size) {
        indices.resize(size);
        for (int i = 0; i < size; ++i)
            indices[i] = i;
    }

    void sortProductsByCategory(std::vector<int>& products) {
        std::sort(indices.begin(), indices.end(), [&products](int a, int b) {
            return products[a].category < products[b].category;
        });
    }

    void sortProductsByName(std::vector<int>& products) {
        std::sort(indices.begin(), indices.end(), [&products](int a, int b) {
            return products[a].name < products[b].name;
        });
    }

    void sortProductsBySeller(std::vector<int>& products) {
        std::sort(indices.begin(), indices.end(), [&products](int a, int b) {
            return products[a].seller < products[b].seller;
        });
    }

    void sortProductsByPrice(std::vector<int>& products) {
        std::sort(indices.begin(), indices.end(), [&products](int a, int b) {
            return products[a].price < products[b].price;
        });
    }

    void sortProductsByRating(std::vector<int>& products) {
        std::sort(indices.begin(), indices.end(), [&products](int a, int b) {
            return products[a].rating > products[b].rating;
        });
    }

    int getProductAtIndex(int index, const std::vector<int>& products) const {
        return indices[index];
    }

private:
    int size;
    std::vector<int> indices;
};

struct Product {
    std::string category;
    std::string name;
    std::string seller;
    double price;
    double rating;
};

int main() {
    std::vector<Product> products = {
        {"Electronics", "Laptop", "ABC Electronics", 1200.0, 4.5},
        {"Clothing", "T-Shirt", "XYZ Clothing", 25.0, 4.0},
        {"Electronics", "Smartphone", "PQR Electronics", 800.0, 4.2}
    };

    IndirectArray indirectArray(products.size());

    indirectArray.sortProductsByCategory(products);
    indirectArray.sortProductsByName(products);
    indirectArray.sortProductsBySeller(products);
    indirectArray.sortProductsByPrice(products);
    indirectArray.sortProductsByRating(products);

    std::cout << "Sorted indices:\n";
    for (int i = 0; i < products.size(); ++i) {
        std::cout << indirectArray.getProductAtIndex(i, products) << " ";
    }
    std::cout << std::endl;

    return 0;
}
