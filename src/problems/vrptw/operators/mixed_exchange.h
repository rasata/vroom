#ifndef VRPTW_MIXED_EXCHANGE_H
#define VRPTW_MIXED_EXCHANGE_H

/*

This file is part of VROOM.

Copyright (c) 2015-2018, Julien Coupey.
All rights reserved (see LICENSE).

*/

#include "problems/cvrp/operators/mixed_exchange.h"
#include "structures/vroom/tw_route.h"

class vrptwMixedExchange : public CVRPMixedExchange {
private:
  TWRoute& _tw_s_route;
  TWRoute& _tw_t_route;

  bool _s_is_normal_valid;
  bool _s_is_reverse_valid;

  virtual void compute_gain() override;

public:
  vrptwMixedExchange(const Input& input,
                     const SolutionState& sol_state,
                     TWRoute& tw_s_route,
                     Index s_vehicle,
                     Index s_rank,
                     TWRoute& tw_t_route,
                     Index t_vehicle,
                     Index t_rank);

  virtual bool is_valid() override;

  virtual void apply() override;
};

#endif