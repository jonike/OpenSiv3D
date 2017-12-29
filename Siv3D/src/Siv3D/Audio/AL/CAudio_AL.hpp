//-----------------------------------------------
//
//	This file is part of the Siv3D Engine.
//
//	Copyright (c) 2008-2017 Ryo Suzuki
//	Copyright (c) 2016-2017 OpenSiv3D Project
//
//	Licensed under the MIT License.
//
//-----------------------------------------------

# pragma once
# include <Siv3D/Platform.hpp>

# if defined(SIV3D_TARGET_MACOS) || defined(SIV3D_TARGET_LINUX)

# include "Audio_AL.hpp"
# include "../IAudio.hpp"
# include "../../AssetHandleManager/AssetHandleManager.hpp"

namespace s3d
{
	class CAudio_AL : public ISiv3DAudio
	{
	private:
		
		ALCdevice* m_device = nullptr;
		
		ALCcontext* m_context = nullptr;
		
		AssetHandleManager<AudioID, Audio_AL> m_audios{ U"Audio" };

	public:

		CAudio_AL();

		~CAudio_AL() override;
		
		bool hasAudioDevice() const override;

		bool init() override;

		AudioID create(Wave&& wave) override;

		void release(AudioID handleID) override;

		uint32 samplingRate(AudioID handleID) override;

		size_t samples(AudioID handleID) override;

		void setLoop(AudioID handleID, bool loop, int64 loopBeginSample, int64 loopEndSample) override;

		bool play(AudioID handleID, const SecondsF& fadeinDuration) override;

		void pause(AudioID handleID, const SecondsF& fadeoutDuration) override;

		void stop(AudioID handleID, const SecondsF& fadeoutDuration) override;

		void playOneShot(AudioID handleID, double volume, double pitch) override;
		
		void stopAllShots(AudioID handleID) override;
		
		bool isPlaying(AudioID handleID) override;

		bool isPaused(AudioID handleID) override;

		uint64 posSample(AudioID handleID) override;

		uint64 streamPosSample(AudioID handleID) override;

		uint64 samplesPlayed(AudioID handleID) override;

		const Wave& getWave(AudioID handleID) override;

		void setVolume(AudioID handleID, const std::pair<double, double>& volume) override;

		std::pair<double, double> getVolume(AudioID handleID) override;

		void setSpeed(AudioID handleID, double speed) override;

		double getSpeed(AudioID handleID) override;

		std::pair<double, double> getMinMaxSpeed(AudioID handleID) override;

		bool updateFade() override;

		void fadeMasterVolume() override;
	};
}

# endif