/*  
    You're given an array of integers asteroids,
    where each integer represents the size of an asteroid.
    The sign of the integer represents the direction the asteroid 
    is moving (positive = right, negative = left). All asteroids
    move at the same speed, meaning that two asteroids moving in the same direction can never collide.
    For example, the integer 4 represents an asteroid
    of size 4 moving to the right. Similarly, -7 represents
    an asteroid of size 7 moving to the left.
    If two asteroids collide, the smaller asteroid (based on absolute value) explodes.
    If two colliding asteroids are the same size, they both explode.
    Write a function that takes in this array of asteroids and returns
    an array of integers representing the asteroids after all collisions occur.
    Ex : asteroids = [-3, 5, -8, 6, 7, -4, -7]
    output : [-3, -8, 6] // The -3 moves left, having no collisions.
                        // The 5 moves right, colliding with the -8 and being destroyed by it.
                        // The 6 never collides with another asteroid.
                        // The 7 first collides with the -4, destroying it.
                        // The 7 and the -7 then collide, both being destroyed.
*/

/*
    The idea is that for every asteroid moving left, we need to compare it the asteroids that we still have which are moving to the right
    and see if it will be destroyed or will destroy others. This is why a stack is a good data structure to tackle this problem
*/

using namespace std;

vector<int> collidingAsteroids(vector<int> asteroids) {
  vector<int> right_asteroids;
  vector<int> left_asteroids;
  for (int i = 0; i<asteroids.size(); i++){
    if (asteroids[i]>0){
      right_asteroids.push_back(asteroids[i]);
    } else {
      while (!right_asteroids.empty() && abs(asteroids[i])>right_asteroids[right_asteroids.size()-1]){
        right_asteroids.pop_back();
      }
      if (right_asteroids.empty()){
        left_asteroids.push_back(asteroids[i]);
      } else if (abs(asteroids[i])==right_asteroids[right_asteroids.size()-1]){
        right_asteroids.pop_back();
      }
    }
  }
  left_asteroids.insert(left_asteroids.end(),right_asteroids.begin(),right_asteroids.end());
  return left_asteroids;
}


// The same code with only one array : 
using namespace std;

vector<int> collidingAsteroids(vector<int> asteroids) {
  vector<int> result;
  for (int i = 0; i<asteroids.size(); i++){
    if (asteroids[i]>0){
      result.push_back(asteroids[i]);
    } else {
      while (!result.empty() && result[result.size()-1]>0 && abs(asteroids[i])>result[result.size()-1]){
        result.pop_back();
      }
      if (result.empty() || result[result.size()-1]<0){ // the asteroid i passed through all the asteroids coming his way and destroyed them and will be stored
        result.push_back(asteroids[i]);
      } else if (abs(asteroids[i])==result[result.size()-1]){ // the asteroid i passed through some asteroids but found an asteroid with same size so they both explode
        result.pop_back();
      }
      // we take no action if the asteroid i gets destroyed by a bigger asteroid
    }
  }
  return result;
}
