// Lab 06
// Harris Pyo and Justin Chen

#include "box.hh"

#include <cmath>
#include <numbers>
using namespace std;
using namespace std::numbers;

// I am sorry that this is very had to follow, but basically the code buids each
// layer in a grid patter, but that requires two different loops, one where the
// y increases for every x and one where the x increases for every y. This
// creates the grid pattern. This is done all the way up to the given thickness
// where the box should start to hollow out. At that point the function still
// creates the grid the same way, but just avoids filling in the center of the
// box and creates a wall based on the given thickness by ignoring the center
// when filling it in. This can be seen with test.gcode file. *Helps to see the
// open top box if rapid movement and toolpath points are turned off in the
// settings at the bottom*

void box::draw_layer(ostream& gc, double x, double y, double layer_thickness,
                     double z) const {
  goto_xyz(gc, x, y, z);
  bool next = true;
  double currentX = 0;
  double currentY = 0;
  // checks if the layer should be hollow (the inside of the box)
  if (z <= t) {
    // builds the box using a back and forth pattern along the x
    while (currentX <= x + L) {
      if (next) {
        while (currentY < y + W) {
          squirt_toxy(gc, currentX, currentY);
          currentY += layer_thickness;
          next = false;
        }
      } else {
        currentY -= layer_thickness;
        while (currentY >= 0 - layer_thickness) {
          squirt_toxy(gc, currentX, currentY);
          currentY -= layer_thickness;
          next = true;
        }
        currentY = 0;
      }
      currentX++;
    }
    goto_xy(gc, x, y);
    currentY = x;
    currentX = y;
    next = true;
    // builds a box using a back and forth pattern along the y
    while (currentY <= y + L) {
      if (next) {
        while (currentX < x + W) {
          squirt_toxy(gc, currentX, currentY);
          currentX += layer_thickness;
          next = false;
        }
      } else {
        currentX -= layer_thickness;
        while (currentX >= 0 - layer_thickness) {
          squirt_toxy(gc, currentX, currentY);
          currentX -= layer_thickness;
          next = true;
        }
        currentX = 0;
      }
      currentY++;
    }
  }
  // when the layer is at the height when the center should be hollow and not
  // printed on
  else {
    // builds the boxes along the x if it is within the box wall thickness
    while (currentX <= x + L) {
      if (currentX <= t || (currentX >= (L - t) && currentX <= (x + L))) {
        if (next) {
          while (currentY < y + W) {
            squirt_toxy(gc, currentX, currentY);
            currentY += layer_thickness;
            next = false;
          }
        } else {
          currentY -= layer_thickness;
          while (currentY >= 0 - layer_thickness) {
            squirt_toxy(gc, currentX, currentY);
            currentY -= layer_thickness;
            next = true;
          }
          currentY = 0;
        }
        currentX++;
      } else {  // builds the box walls along the x but ignores the center to
                // create walls with the given thickness
        if (next) {
          while (currentY < y + W) {
            if (currentY > t && currentY < (W - t)) {
              goto_xy(gc, currentX, currentY);
            } else {
              squirt_toxy(gc, currentX, currentY);
            }
            currentY += layer_thickness;
            next = false;
          }
        } else {
          currentY -= layer_thickness;
          while (currentY >= 0 - layer_thickness) {
            if (currentY > t && currentY < (W - t)) {
              goto_xy(gc, currentX, currentY);
            } else {
              squirt_toxy(gc, currentX, currentY);
            }
            currentY -= layer_thickness;
            next = true;
          }
          currentY = 0;
        }
        currentX++;
      }
    }

    goto_xy(gc, x, y);
    currentY = x;
    currentX = y;
    next = true;
    while (currentY <= y + W) {  // builds the boxes along the y if it is within
                                 // the box wall thickness
      if (currentY <= t || (currentY >= (W - t) && currentY <= (y + L))) {
        if (next) {
          while (currentX < x + L) {
            squirt_toxy(gc, currentX, currentY);
            currentX += layer_thickness;
            next = false;
          }
        } else {
          currentX -= layer_thickness;
          while (currentX >= 0 - layer_thickness) {
            squirt_toxy(gc, currentX, currentY);
            currentX -= layer_thickness;
            next = true;
          }
          currentX = 0;
        }
        currentY++;
      } else {  // builds the box walls along the y but ignores the center to
                // create walls with the given thickness
        if (next) {
          while (currentX < x + L) {
            if (currentX > t && currentX < (W - t)) {
              goto_xy(gc, currentX, currentY);
            } else {
              squirt_toxy(gc, currentX, currentY);
            }
            currentX += layer_thickness;
            next = false;
          }
        } else {
          currentX -= layer_thickness;
          while (currentX >= 0 - layer_thickness) {
            if (currentX > t && currentX < (L - t)) {
              goto_xy(gc, currentX, currentY);
            } else {
              squirt_toxy(gc, currentX, currentY);
            }
            currentX -= layer_thickness;
            next = true;
          }
          currentX = 0;
        }
        currentY++;
      }
    }
  }
}

double box::height() const { return H; }