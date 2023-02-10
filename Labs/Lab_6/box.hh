// Lab 06
// Harris Pyo and Justin Chen

#pragma once

#include "shape.hh"

class box : public shape {  // a box is_a shape
 private:
  double t;  // wall thickness
  double L;  // length
  double W;  // width
  double H;  // height

 public:
  box(double t, double L, double W, double H) : t(t), L(L), W(W), H(H) {}
  void draw_layer(std::ostream& gc, double x, double y, double layer_thickness,
                  double z) const override;
  double height() const override;
};
