/*
** Xp.cpp for MyPokemon in /home/quief_h/rendu/MyPokemon/src/game/Xp
**
** Made by Hippolyte QUIEF
** Login   <quief_h@epitech.net>
**
** Started on  Tue Jun  9 11:34:28 2015 Hippolyte QUIEF
** Last update Tue Jun  9 16:37:32 2015 Hippolyte QUIEF
*/

#include	<cmath>
#include	"game/xp.hpp"

using namespace	game;

# define	SQR(value)	(value * value)
# define	CUB(value)	(value * value * value)

/*
** Fonction static
*/
namespace
{
  unsigned int		erratic_xp(unsigned int lv)
  {
    unsigned int	xp;

    if (lv < 50)
      xp = ((CUB(lv) * (100 - lv)) / 50);
    else if (lv >= 50 && lv < 68)
      xp = ((CUB(lv) * (150 - lv)) / 100);
    else if (lv >=  68 && lv < 98)
      xp = ((CUB(lv) * (1911 - 10 * lv)) / 3) / 500;
    else
      xp = ((CUB(lv) * (160 - lv)) / 50);
    return (xp);
  }

  unsigned int		fast_xp(unsigned int lv)
  {
    unsigned int	xp;

    xp = ((4 * CUB(lv)) / 5);
    return (xp);
  }

  unsigned int		med_fast_xp(unsigned int lv)
  {
    unsigned int	xp;

    xp = CUB(lv);
    return (xp);
  }

  unsigned int		med_slow_xp(unsigned int lv)
  {
    unsigned int	xp;

    xp = (6 / 5) * CUB(lv) - 15 * SQR(lv) + 100 * lv - 140;
    return (xp);
  }

  unsigned int		slow_xp(unsigned int lv)
  {
    unsigned int	xp;

    xp = (5 * CUB(lv)) / 4;
    return (xp);
  }

  unsigned int		fluctuating_xp(unsigned int lv)
  {
    unsigned int	xp;

    if (lv < 15)
      xp = CUB(lv) * (((lv + 1) / 3) + 24 ) / 50;
    else if (lv >= 15 && lv < 36)
      xp = CUB(lv) * ((lv + 14) / 50);
    else
      xp = CUB(lv) * (((lv / 2) + 32) / 50);
    return (xp);
  }

  e_xp_type		xp_type(unsigned int xp_max)
  {
    e_xp_type		ret;

    switch (xp_max)
      {
      case (600000):
	ret = XP_ERRATIC;
	break;

      case (800000):
	ret = XP_FAST;
	break;

      case (1000000):
	ret = XP_MED_FAST;
	break;

      case (1059860):
	ret = XP_MED_SLOW;
	break;

      case (1250000):
	ret = XP_SLOW;
	break;

      default:
      case (1640000):
	ret = XP_FLUCTUATING;
	break;
      }
    return (ret);
  }

  unsigned int		calc_xp(unsigned int current_lv, unsigned int next_lv,
				e_xp_type xp_type)
  {
    unsigned int	xp;

    if (xp_type == XP_ERRATIC)
      xp = erratic_xp(next_lv) - erratic_xp(current_lv);
    else if (xp_type == XP_FAST)
      xp = fast_xp(next_lv) - fast_xp(current_lv);
    else if (xp_type == XP_MED_FAST)
      xp = med_fast_xp(next_lv) - med_fast_xp(current_lv);
    else if (xp_type == XP_MED_SLOW)
      xp = med_slow_xp(next_lv) - med_slow_xp(current_lv);
    else if (xp_type == XP_SLOW)
      xp = slow_xp(next_lv) - slow_xp(current_lv);
    else
      xp = fluctuating_xp(next_lv) - fluctuating_xp(current_lv);
    return (xp);
  }

  unsigned int		calc_xp_to_next_lv(unsigned int lv, unsigned int current_xp,
					   unsigned int xp_max)
  {
    unsigned int	xp_need;

    xp_need = calc_xp(lv, lv + 1, xp_type(xp_max)) - current_xp;
    return (xp_need);
  }
}

/*
** @brief	Renvoie le nombre de niveau gagne
**
** @param	level	Niveau actuel du pokemon
** @return	Nombre de niveau gagne
*/
unsigned int		nb_level_pass(unsigned int level, unsigned int current_xp,
				      unsigned int xp_gain, unsigned int xp_max)
{
  unsigned int	lv;

  lv = 0;
  while (xp_gain > calc_xp_to_next_lv(level + lv, current_xp, xp_max))
    {
      xp_gain -= calc_xp_to_next_lv(level + lv, current_xp, xp_max);
      lv++;
    }
  return (lv);
}
