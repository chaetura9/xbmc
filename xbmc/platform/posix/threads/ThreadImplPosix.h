/*
 *  Copyright (C) 2005-2018 Team Kodi
 *  This file is part of Kodi - https://kodi.tv
 *
 *  SPDX-License-Identifier: GPL-2.0-or-later
 *  See LICENSES/README.md for more information.
 */

#pragma once

#include "threads/IThreadImpl.h"
#include "threads/SingleLock.h"

class CThreadImplPosix : public IThreadImpl
{
public:
  CThreadImplPosix(std::thread::native_handle_type handle);

  ~CThreadImplPosix() override = default;

  void SetThreadInfo(const std::string& name) override;

  bool SetPriority(const ThreadPriority& priority) override;

private:
  CCriticalSection m_criticalSection;

  pid_t m_threadID;
};
