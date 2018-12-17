#ifndef LOCAL_SEARCH_H
#define LOCAL_SEARCH_H

/*

This file is part of VROOM.

Copyright (c) 2015-2018, Julien Coupey.
All rights reserved (see LICENSE).

*/

#include "structures/vroom/raw_route.h"
#include "structures/vroom/solution_state.h"
#include "structures/vroom/tw_route.h"

template <class Route,
          class Exchange,
          class CrossExchange,
          class MixedExchange,
          class TwoOpt,
          class ReverseTwoOpt,
          class Relocate,
          class OrOpt,
          class IntraExchange,
          class IntraCrossExchange,
          class IntraMixedExchange,
          class IntraRelocate,
          class IntraOrOpt>
class LocalSearch {
private:
  const Input& _input;
  const Matrix<Cost>& _matrix;
  const std::size_t _nb_vehicles;
  const Amount _amount_lower_bound;
  const Amount _double_amount_lower_bound;

  const unsigned _max_nb_jobs_removal;
  std::vector<Index> _all_routes;

  SolutionState _sol_state;

  std::vector<Route> _sol;

  std::vector<Route>& _best_sol;
  unsigned _best_unassigned;
  Cost _best_cost;

  void try_job_additions(const std::vector<Index>& routes, double regret_coeff);

  void run_ls_step();

  void remove_from_routes();

public:
  LocalSearch(const Input& input,
              std::vector<Route>& tw_sol,
              unsigned max_nb_jobs_removal);

  SolutionIndicators indicators() const;

  void run();
};

#endif