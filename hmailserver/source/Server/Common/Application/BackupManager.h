// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#pragma once

namespace HM
{
   class Backup;

   class BackupManager
   {
   public:
      BackupManager(void);
      ~BackupManager(void);

      bool StartBackup();
      // Backups the server according to the settings
      // specified in the configuration.

      shared_ptr<Backup> LoadBackup(const String &sZipFile) const;
      // Loads a backup from an XML stream and returns
      // an backup object that contains backup information.

      bool StartRestore(shared_ptr<Backup> pBackup);
      // Starts a restore of the backup. Restors the part of the
      // backup specified by iRestoreMode.

      void OnThreadStopped();
      // Called by backup/restore thread when operation has finished.

      void SetStatus(const String &sStatus);
      String GetStatus();

      void OnBackupCompleted();
      void OnBackupFailed(const String &sReason);
 
   private:

      boost::recursive_mutex _mutex;
      String m_sLog;
      bool m_bIsRunning;
   };
}