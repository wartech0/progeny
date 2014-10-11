#ifndef CANDIDATE_H 
#define CANDIDATE_H 

#include <utility>
#include <type_traits>

namespace pr {
  template <typename BType, typename FitType, class Enable = void>
  class Candidate;

  //! Encapsulates the basic population member type.
  /*!
  *  \tparam BType Base type of population member.
  *  \tparam FitType Type of the fitness quantity.
  */
  template <typename BType, typename FitType>
  class Candidate<
    BType, 
    FitType,
    typename std::enable_if<std::is_arithmetic<FitType>::value>::type
  > : public std::pair<BType, FitType> {

    public:
      typedef BType BaseType;
      typedef FitType FitnessType;

    public:
      Candidate() : std::pair<BType, FitType>() {}
      Candidate(BType b, FitType f) : std::pair<BType, FitType>(b, f) {}
      Candidate(BType b) : std::pair<BType, FitType>(b, FitType()) {}
  };

  template <typename BType, typename FitType>
  auto fitness(Candidate<BType, FitType>& cnd) -> decltype(std::get<1>(cnd)) {
    return std::get<1>(cnd);
  }

  template <typename BType, typename FitType>
  auto fitness(const Candidate<BType, FitType>& cnd) -> decltype(std::get<1>(cnd)) {
    return std::get<1>(cnd);
  }

  template <typename BType, typename FitType>
  auto progeny(Candidate<BType, FitType>& cnd) -> decltype(std::get<0>(cnd)) {
    return std::get<0>(cnd);
  }

  template <typename BType, typename FitType>
  auto progeny(const Candidate<BType, FitType>& cnd) -> decltype(std::get<0>(cnd)) {
    return std::get<0>(cnd);
  }
    
}
#endif
