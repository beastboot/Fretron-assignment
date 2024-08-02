#include <iostream>
#include <vector>
#include <algorithm>

struct Person {
    std::string name;
    int amount_paid;
    int total_weight;
    std::vector<int> apples;
};

void input_apple_weights(std::vector<int>& apple_weights) {
    int weight;
    std::cout << "Enter apple weight in gram (-1 to stop): ";
    while (std::cin >> weight && weight != -1) {
        apple_weights.push_back(weight);
        std::cout << "Enter apple weight in gram (-1 to stop): ";
    }
}

void sort_apple_weights(std::vector<int>& apple_weights) {
    std::sort(apple_weights.begin(), apple_weights.end(), std::greater<int>());
}

int calculate_total_money(const std::vector<Person>& people) {
    int total_money = 0;
    for (const auto& person : people) {
        total_money += person.amount_paid;
    }
    return total_money;
}

int calculate_total_weight(const std::vector<int>& apple_weights) {
    int total_weight = 0;
    for (const auto& weight : apple_weights) {
        total_weight += weight;
    }
    return total_weight;
}

void distribute_apples(std::vector<int>& apple_weights, Person& person, int target_weight) {
    int current_weight = 0;
    for (auto it = apple_weights.begin(); it != apple_weights.end(); ) {
        if (current_weight + *it <= target_weight) {
            current_weight += *it;
            person.apples.push_back(*it);
            it = apple_weights.erase(it);
        } else {
            ++it;
        }
    }
    person.total_weight = current_weight;
}

void distribute_apples_to_people(std::vector<int>& apple_weights, std::vector<Person>& people, int total_money, int total_weight) {
    for (auto& person : people) {
        int target_weight = (person.amount_paid * total_weight) / total_money;
        distribute_apples(apple_weights, person, target_weight);
    }
}

void display_distribution_result(const std::vector<Person>& people, int total_weight) {
    std::cout << "Distribution Result:\n";
    for (const auto& person : people) {
        std::cout << person.name << " : ";
        for (const auto& apple : person.apples) {
            std::cout << apple << "g ";
        }
        std::cout << "(total " << person.total_weight << "g, " << (person.total_weight * 100) / total_weight << "%)\n";
    }
}

int main() {
    std::vector<Person> people = {
        {"Ram", 50, 0, {}},
        {"Sham", 30, 0, {}},
        {"Rahim", 20, 0, {}}
    };

    std::vector<int> apple_weights;
    input_apple_weights(apple_weights);

    sort_apple_weights(apple_weights);

    int total_money = calculate_total_money(people);
    int total_weight = calculate_total_weight(apple_weights);

    distribute_apples_to_people(apple_weights, people, total_money, total_weight);

    display_distribution_result(people, total_weight);

    return 0;
}
