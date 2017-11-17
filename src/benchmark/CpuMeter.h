/**
 * Copyright 2017, Intel Corporation
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in
 *       the documentation and/or other materials provided with the
 *       distribution.
 *
 *     * Neither the name of the copyright holder nor the names of its
 *       contributors may be used to endorse or promote products derived
 *       from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef SRC_BENCHMARK_CPUMETER_H_
#define SRC_BENCHMARK_CPUMETER_H_

#include <boost/timer/timer.hpp>
#include <tuple>
#include <vector>
#include <string>

#include <CPUSnapshot.h>

#include <csv/writer.hpp>

#include "SimFogKV.h"

using namespace boost::timer;

namespace FogKV
{

class CpuMeter {
public:
	CpuMeter(bool enableCSV);
	virtual ~CpuMeter();

	void start();
	void stop();

	std::tuple<unsigned short, cpu_times> getCpuUsage();

	std::string format();

	void logCpuUsage(FogKV::SimFogKV* simFog);

private:
	bool _csvEnabled;
	cpu_timer _timer;
	std::unique_ptr<CPUSnapshot> _spLastSnapshot;
	std::string _csvFileName;
};

} /* namespace Dragon */

#endif /* SRC_BENCHMARK_CPUMETER_H_ */