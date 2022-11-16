#pragma once
#include <QWidget>
#include "lobby.h"

namespace Ui {
class Lobby;
}

class Lobby : public QWidget
{
	Q_OBJECT

public:
	explicit Lobby(QWidget *parent = nullptr);
	~Lobby();

private slots:
	void on_messageEdit_returnPressed();

	void chatMessage(QString title, QString body, bool isSystem = false);
	void sysMessage(QString body);
	void dispatchMessage(QString);
	void serverCommand(const ServerCommand &);

	void on_connectButton_toggled(bool checked);

	void on_newButton_clicked();

	void on_joinButton_clicked();

	void on_buttonLeave_clicked();

	void on_buttonReady_clicked();

	void onDisconnected();

private:
	Ui::Lobby *ui;
	SocketLobby socketLobby;
	QString hostSession;
	QString session;
	QString username;
	QStringList gameArgs;

	enum AuthStatus
	{
		NONE, OK, ERROR
	};

	AuthStatus authentificationStatus = NONE;

private:
	QMap<QString, QString> buildModsMap() const;
	bool isModAvailable(const QString & modName, const QString & modVersion) const;


	void protocolAssert(bool);
};
