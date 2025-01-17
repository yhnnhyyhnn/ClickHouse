#include "MySQLHelpers.h"

#if USE_MYSQL
#include <mysqlxx/PoolWithFailover.h>
#include <Storages/ExternalDataSourceConfiguration.h>
#include <Storages/MySQL/MySQLSettings.h>

namespace DB
{

mysqlxx::PoolWithFailover
createMySQLPoolWithFailover(const StorageMySQLConfiguration & configuration, const MySQLSettings & mysql_settings)
{
    return mysqlxx::PoolWithFailover(
        configuration.database, configuration.addresses, configuration.username, configuration.password,
        MYSQLXX_POOL_WITH_FAILOVER_DEFAULT_START_CONNECTIONS,
        mysql_settings.connection_pool_size,
        mysql_settings.connection_max_tries,
        mysql_settings.connection_wait_timeout,
        mysql_settings.connect_timeout,
        mysql_settings.read_write_timeout);
}

}

#endif
