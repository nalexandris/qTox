/*
    Copyright © 2015 by The qTox Project Contributors

    This file is part of qTox, a Qt-based graphical interface for Tox.

    qTox is libre software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    qTox is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with qTox.  If not, see <http://www.gnu.org/licenses/>.
*/


#ifndef TOXID_H
#define TOXID_H

#include <QString>

class ToxId
{
public:
    ToxId();
    ToxId(const ToxId& other);
    explicit ToxId(const QString& id);
    explicit ToxId(const QByteArray& rawId);
    explicit ToxId(const uint8_t* rawId, int len);

    bool operator==(const ToxId& other) const;
    bool operator!=(const ToxId& other) const;
    QString toString() const;
    void clear();
    bool isValid() const;

    static bool isValidToxId(const QString& id);
    static bool isToxId(const QString &id);
    const uint8_t* getBytes() const;
    QByteArray getToxId() const;
    QByteArray getPublicKey() const;
    const uint8_t* getPublicKeyBytes() const;
    QString getPublicKeyString() const;
    QString getNoSpamString() const;

private:
    void constructToxId(const QByteArray& rawId);

public:
    static const QRegularExpression ToxIdRegEx;

private:
    QByteArray toxId;
};

#endif // TOXID_H
