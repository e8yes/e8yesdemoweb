/**
 * e8yes demo web.
 *
 * <p>Copyright (C) 2020 Chifeng Wen {daviesx66@gmail.com}
 *
 * <p>This program is free software: you can redistribute it and/or modify it under the terms of the
 * GNU General Public License as published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 *
 * <p>This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 * without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * <p>You should have received a copy of the GNU General Public License along with this program. If
 * not, see <http://www.gnu.org/licenses/>.
 */

#ifndef DEMOWEB_ENVIRONMENT_CONTEXT_INTERFACE_H
#define DEMOWEB_ENVIRONMENT_CONTEXT_INTERFACE_H

#include <vector>

#include "demoweb_service/demoweb/environment/host_id.h"
#include "demoweb_service/demoweb/pbac/message_channel_pbac.h"
#include "keygen/key_generator_interface.h"
#include "message_queue/publisher/publisher.h"
#include "postgres/query_runner/connection/connection_reservoir_interface.h"

namespace e8 {

/**
 * @brief The EnvironmentContextInterface class Returns global objects the runs in a deployment
 * environment.
 */
class DemoWebEnvironmentContextInterface {
  public:
    enum Environment { PROD, TEST };

    DemoWebEnvironmentContextInterface() = default;
    DemoWebEnvironmentContextInterface(DemoWebEnvironmentContextInterface const &) = delete;
    virtual ~DemoWebEnvironmentContextInterface() = default;

    /**
     * The type of deployment environment it implements.
     *
     * @return Environment type.
     */
    virtual Environment EnvironmentType() const = 0;

    /**
     * @brief CurrentHostId Returns the host ID of the current machine it is running on.
     */
    virtual HostId CurrentHostId() const = 0;

    /**
     * @brief Connections to the DemoWeb database server.
     */
    virtual ConnectionReservoirInterface *DemowebDatabase() = 0;

    /**
     * @brief KeyGen Cryptographic key generator.
     */
    virtual KeyGeneratorInterface *KeyGen() = 0;

    /**
     * @brief MessagePublisher A collection of client message push facilities.
     */
    virtual std::vector<MessagePublisherInterface *> ClientPushMessagePublishers() = 0;

    /**
     * @brief MessageChannelPbac Message channel access controller.
     */
    virtual MessageChannelPbacInterface *MessageChannelPbac() = 0;
};

/**
 * @brief RegisterEnvironment Register the specified environment to be the currently active
 * environment.
 */
void RegisterEnvironment(DemoWebEnvironmentContextInterface *env);

/**
 * @brief CurrentEnvironment Retrieve the currently registered environment context. The returned
 * context is guaranteed to be not null. If no environment is registered, this function will fail.
 */
DemoWebEnvironmentContextInterface *DemoWebEnvironment();

} // namespace e8

#endif // DEMOWEB_ENVIRONMENT_CONTEXT_INTERFACE_H
