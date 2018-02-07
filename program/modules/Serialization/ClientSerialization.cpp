#include <qt5/QtCore/qdatastream.h>
#include <Client.h>
#include <modules/QtAdapters/ClientQtAdapter/ClientQtAdapter.h>
#include <Address.h>
#include <memory>
#include <tuple>
#include <QMessageBox>
#include <qt5/QtCore/qstring.h>

inline QDataStream &operator<<(QDataStream &out, const shared_ptr<Client> client) {
	return out;
}

inline QDataStream &operator>>(QDataStream &in, unique_ptr<Client> client) {
    return in;
}


