//## begin module%37C533BB02FB.cm preserve=no
/*
 * Merlin C++ Class Library for Charged Particle Accelerator Simulations
 * 
 * Class library version 2.0 (2000)
 * 
 * file Merlin\BeamDynamics\ParticleTracking\ParticleBunchConstructor.h
 * last modified 26/04/01 10:44:51
 */
//## end module%37C533BB02FB.cm

//## begin module%37C533BB02FB.cp preserve=no
/*
 * This file is derived from software bearing the following
 * restrictions:
 *
 * MERLIN C++ class library for 
 * Charge Particle Accelerator Simulations
 *
 * Copyright (c) 2000 by The Merlin Collaboration.  
 * ALL RIGHTS RESERVED. 
 *
 * Permission to use, copy, modify, distribute and sell this
 * software and its documentation for any purpose is hereby
 * granted without fee, provided that the above copyright notice
 * appear in all copies and that both that copyright notice and
 * this permission notice appear in supporting documentation.
 * No representations about the suitability of this software for
 * any purpose is made. It is provided "as is" without express
 * or implied warranty.
 */
//## end module%37C533BB02FB.cp

//## Module: ParticleBunchConstructor%37C533BB02FB; Package specification
//## Subsystem: Merlin::BeamDynamics::ParticleTracking%3729F894017C
//## Source file: D:\dev\Merlin\BeamDynamics\ParticleTracking\ParticleBunchConstructor.h

#ifndef ParticleBunchConstructor_h
#define ParticleBunchConstructor_h 1

//## begin module%37C533BB02FB.additionalIncludes preserve=no
#include "merlin_config.h"
//## end module%37C533BB02FB.additionalIncludes

//## begin module%37C533BB02FB.includes preserve=yes
//## end module%37C533BB02FB.includes

// ParticleBunch
#include "BeamDynamics/ParticleTracking/ParticleBunch.h"
// BunchConstructor
#include "BeamModel/BunchConstructor.h"
// BeamData
#include "BeamModel/BeamData.h"
// MatrixMaps
#include "BasicTransport/MatrixMaps.h"
//## begin module%37C533BB02FB.declarations preserve=no
//## end module%37C533BB02FB.declarations

//## begin module%37C533BB02FB.additionalDeclarations preserve=yes
//## end module%37C533BB02FB.additionalDeclarations


//## Class: ParticleBunchFilter%37C532580138; Abstract
//## Category: Merlin::BeamDynamics::ParticleTracking%36E7A9AD0176
//## Subsystem: Merlin::BeamDynamics::ParticleTracking%3729F894017C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class ParticleBunchFilter 
{
  public:
    //## Destructor (specified)
      //## Operation: ~ParticleBunchFilter%935667559
      virtual ~ParticleBunchFilter ();


    //## Other Operations (specified)
      //## Operation: Apply%935667560
      //	Used by a ParticleBunchConstructor object to select
      //	vectors for inclusion in a ParticleBunch.
      virtual bool Apply (const PSvector& v) const = 0;

  protected:
  private:
  private:  //## implementation
};

//## Class: DistributionType%37C53438025B
//## Category: Merlin::BeamDynamics::ParticleTracking%36E7A9AD0176
//## Subsystem: Merlin::BeamDynamics::ParticleTracking%3729F894017C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

typedef enum {normalDistribution,flatDistribution} DistributionType;

//## Class: ParticleBunchConstructor%3729CF42029E
//	Constructs a particle bunch with random particles taken
//	from a 6D distribution. The phase space moments are
//	supplied as a BeamData struct. The form of the
//	distribution can be either normal (Gaussian), in which
//	case the data supplied in the BeamData struct is
//	interpreted as  RMS values, or flat, in which case the
//	data specifies the +- extents for a flat (rectangular)
//	distribution.
//
//	An additional ParticleBunchFilter can be specified which
//	can further be used to modify the phase space
//	distribution generated.
//## Category: Merlin::BeamDynamics::ParticleTracking%36E7A9AD0176
//## Subsystem: Merlin::BeamDynamics::ParticleTracking%3729F894017C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: constructs%3729CF61032A;ParticleBunch { -> }
//## Uses: <unnamed>%3729D23200D2;RandomNG { -> }
//## Uses: <unnamed>%37C5359202F8;DistributionType { -> }

class ParticleBunchConstructor : public BunchConstructor  //## Inherits: <unnamed>%3AE6C9760366
{
  public:
    //## Constructors (specified)
      //## Operation: ParticleBunchConstructor%925486244
      //	Constructor taking the beam data and the number of
      //	particles to generate.
      ParticleBunchConstructor (const BeamData& beam, size_t npart, DistributionType dist = normalDistribution);

    //## Destructor (specified)
      //## Operation: ~ParticleBunchConstructor%935667557
      ~ParticleBunchConstructor ();


    //## Other Operations (specified)
      //## Operation: SetBunchData%925486245
      //	Sets the bunch information that will be used to generate
      //	the particle bunch.
      void SetBunchData (const BeamData& beam);

      //## Operation: SetNumParticles%925486246
      //	Sets the number of particles to be generated.
      void SetNumParticles (size_t npart);

      //## Operation: SetDistributionCutoff%958127065
      //	Sets the distribution cut-off in standard deviations.
      //	Passing 0 indicates that no cut-off be applied
      //	(default). Only applies to normal distributions.
      void SetDistributionCutoff (double cut);

      //## Operation: ConstructBunch%925486247
      //	Constructs a new ParticleBunch based on the current
      //	bunch parameter settings. Each call to ConstructBunch
      //	generates a new random distribution (seed).
      virtual Bunch* ConstructBunch () const;

      //## Operation: SetFilter%935667558
      //	Sets the filter to be used during bunch construction. A
      //	NULL pointer indicates no filter.
      void SetFilter (ParticleBunchFilter* filter);

      //## Operation: ConstructParticleBunch%962137992
      //	Returns typed particle bunch.
      ParticleBunch* ConstructParticleBunch () const;

  protected:
  private:
    // Data Members for Class Attributes

      //## Attribute: np%3729D52D0190
      //## begin ParticleBunchConstructor::np%3729D52D0190.attr preserve=no  private: size_t {UA} 
      size_t np;
      //## end ParticleBunchConstructor::np%3729D52D0190.attr

      //## Attribute: dtype%37C532CD02D1
      //## begin ParticleBunchConstructor::dtype%37C532CD02D1.attr preserve=no  private: DistributionType {UA} 
      DistributionType dtype;
      //## end ParticleBunchConstructor::dtype%37C532CD02D1.attr

      //## Attribute: cutOff%391BDBD00048
      //## begin ParticleBunchConstructor::cutOff%391BDBD00048.attr preserve=no  private: double {UA} 
      double cutOff;
      //## end ParticleBunchConstructor::cutOff%391BDBD00048.attr

    // Data Members for Associations

      //## Association: Merlin::BeamDynamics::ParticleTracking::<unnamed>%3729D8430078
      //## Role: ParticleBunchConstructor::beamdat%3729D843007A
      //## begin ParticleBunchConstructor::beamdat%3729D843007A.role preserve=no  private: BeamData { -> 1VHAN}
      BeamData beamdat;
      //## end ParticleBunchConstructor::beamdat%3729D843007A.role

      //## Association: Merlin::BeamDynamics::ParticleTracking::class details::<unnamed>%37C532EE0238
      //## Role: ParticleBunchConstructor::itsFilter%37C532EF0077
      //## begin ParticleBunchConstructor::itsFilter%37C532EF0077.role preserve=no  private: ParticleBunchFilter { -> 0..1VHAN}
      ParticleBunchFilter* itsFilter;
      //## end ParticleBunchConstructor::itsFilter%37C532EF0077.role

      //## Association: Merlin::BeamDynamics::ParticleTracking::class details::<unnamed>%3729D26000B4
      //## Role: ParticleBunchConstructor::M%3729D26003B6
      //	The map used to transform a spherically symmetric
      //	distribution into the desired bunch distribution.
      //## begin ParticleBunchConstructor::M%3729D26003B6.role preserve=no  private: RMtrx { -> 1VHAN}
      RMtrx M;
      //## end ParticleBunchConstructor::M%3729D26003B6.role

  private:  //## implementation
};

// Class ParticleBunchFilter 

// Class ParticleBunchConstructor 


//## Other Operations (inline)
//## Operation: SetFilter%935667558
inline void ParticleBunchConstructor::SetFilter (ParticleBunchFilter* filter)
{
  //## begin ParticleBunchConstructor::SetFilter%935667558.body preserve=yes
	if(itsFilter)
		delete itsFilter;
	itsFilter = filter;
  //## end ParticleBunchConstructor::SetFilter%935667558.body
}

//## Operation: ConstructParticleBunch%962137992
inline ParticleBunch* ParticleBunchConstructor::ConstructParticleBunch () const
{
  //## begin ParticleBunchConstructor::ConstructParticleBunch%962137992.body preserve=yes
	return static_cast<ParticleBunch*>(ParticleBunchConstructor::ConstructBunch());
  //## end ParticleBunchConstructor::ConstructParticleBunch%962137992.body
}

//## begin module%37C533BB02FB.epilog preserve=yes
//## end module%37C533BB02FB.epilog


#endif