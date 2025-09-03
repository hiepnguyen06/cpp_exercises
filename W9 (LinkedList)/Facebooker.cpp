#include <bits/stdc++.h>

class Facebooker {
   private:
    std::string name;
    std::vector<Facebooker *> friends;

   public:
    Facebooker(std::string name, std::vector<Facebooker *> friends = {}) : name(name), friends(friends) {}

    bool isNotFriend(Facebooker *newFriend) {
        for (int i = 0; i < friends.size(); i++) {
            if (newFriend->name == friends[i]->name) {
                std::cout << newFriend->name << " is already friend of " << this->name << std::endl;
                return false;
            }
        }
        return true;
    }

    void addFriend(Facebooker *newFriend) {
        bool noFriendList = friends.empty();
        if (isNotFriend(newFriend) || noFriendList) {
            friends.push_back(newFriend);
            newFriend->friends.push_back(this);
        }
    }

    void viewFriends() {
        if (friends.empty()) return;

        for (int i = 0; i < friends.size(); i++) {
            std::cout << "Friend #" << i + 1 << " : " << friends[i]->name << std::endl;
        }
    }

    void viewFriendsofFriends() {
        int i = 0;
        for (auto *aFriend : friends) {
            for (auto *aFriendOfFriend : aFriend->friends) {
                if (aFriendOfFriend == this) continue;
                std::cout << "Friend of Friend #" << i + 1 << " : " << aFriendOfFriend->name << std::endl;
                i++;
            }
        }
    }

    void viewMutualFriends(Facebooker *theFriend) {
        for (auto *yourFriend : this->friends) {
            for (auto *theirFriend : theFriend->friends) {
                if (theirFriend == this) continue;
                if (theirFriend == yourFriend) {
                    std::cout << "Mutual friend with " << theFriend->name << " : " << theirFriend->name << std::endl;
                }
            }
        }
    }
};

int main() {
    Facebooker personA("Hiep");
    Facebooker personB("Dat");
    Facebooker personC("San");
    Facebooker personD("Vy");

    personA.addFriend(&personB);
    personA.addFriend(&personC);
    personB.addFriend(&personD);
    personB.addFriend(&personC);

    // personD.viewFriendsofFriends();
    personD.viewMutualFriends(&personA);

    return -1;
}