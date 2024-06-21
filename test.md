This is the test for success
```javascript
  it('calls the mutation with right variables and shows toasts', async () => {
    const mockAxios = new MockAdapter(axios);
    mockAxios
      .onPost(`/internal/hyperv/vm/snapshot/mockSnapshotId/mount`)
      .reply(202, {
        id: 'MOUNT_HYPERV_SNAPSHOT_2aebc0b7-f18a-4db5-ae25-0f99ad78f29f_400df7b8-35e3-449f-bbb2-8b198a008186:::0',
        status: 'QUEUED',
        progress: 0.0,
        startTime: '2024-05-04T07:01:00.699Z',
        links: [
          {
            href: 'https://10.0.35.180/api/internal/hyperv/vm/request',
            rel: 'self',
          },
        ],
      });

    render(
      <MockedProviders>
        <Form
          initialValues={{
            ...initialMockEmptyValues,
            selectedHostId: 'mockHostId',
            mountedVMName: 'mockVMName',
          }}
        >
          <HyperVLiveMountRecoveryButton
            closeModal={() => {}}
            snapshotId="mockSnapshotId"
            snappable={{name: 'mockName', id: 'mockSnappableId'}}
          />
        </Form>
      </MockedProviders>,
    );

    const recoverButton = await screen.findByRole('button', {
      name: TID.INVENTORY.HYPERV.RECOVERY_WIZARD.LIVE_MOUNT.MOUNT,
    });
    expect(recoverButton).toBeEnabled();

    await userEvent.click(recoverButton);

    await waitFor(() => {
      expect(mockAxios.history.post).toHaveLength(1);
    });

    expect(mockAxios.history.post[0].data).toMatchInlineSnapshot(
      `"{\\"hostId\\":\\"mockHostId\\",\\"powerOn\\":true,\\"removeNetworkDevices\\":false,\\"vmName\\":\\"mockVMName\\"}"`,
    );

    const toast = await screen.findByRole('alert');
    expect(toast).toHaveTextContent(
      TID.INVENTORY.HYPERV.RECOVERY_WIZARD.SELECT_RECOVERY_OPTION_STEP.OPTIONS
        .INSTANT_RECOVER.SUCCESS_MUTATION,
    );
  });
```
This is the test for failure
```javascript
  it('shows error toast when mutation fails', async () => {
    const mockAxios = new MockAdapter(axios);
    mockAxios
      .onPost(`/internal/hyperv/vm/snapshot/mockSnapshotId/mount`)
      .reply(500, {
        message: `Snapshot mockSnapshotId not found`,
      });

    render(
      <MockedProviders>
        <Form
          initialValues={{
            ...initialMockEmptyValues,
            selectedHostId: 'mockHostId',
          }}
        >
          <HyperVLiveMountRecoveryButton
            closeModal={() => {}}
            snapshotId="mockSnapshotId"
            snappable={{name: 'mockName', id: 'mockSnappableId'}}
          />
        </Form>
      </MockedProviders>,
    );

    const recoverButton = await screen.findByRole('button', {
      name: TID.INVENTORY.HYPERV.RECOVERY_WIZARD.LIVE_MOUNT.MOUNT,
    });
    expect(recoverButton).toBeEnabled();

    await userEvent.click(recoverButton);

    await waitFor(() => {
      expect(mockAxios.history.post).toHaveLength(1);
    });

    expect(mockAxios.history.post[0].data).toMatchInlineSnapshot(
      `"{\\"hostId\\":\\"mockHostId\\",\\"powerOn\\":true,\\"removeNetworkDevices\\":false}"`,
    );

    const toast = await screen.findByRole('alert');
    expect(toast).toHaveTextContent('Snapshot mockSnapshotId not found');
  });
  ```


  Now I'll provide you test for success for another flow, which is similar to the above one. Create failure test for this flow and provide me the code for that.
  ```javascript
  it('calls the mutation with right variables and shows toast', async () => {
    const mockAxios = new MockAdapter(axios);
    const mockSnapshotId = 'mockSnapshotId';
    mockAxios
      .onPost(`/internal/hyperv/vm/snapshot/${mockSnapshotId}/instant_recover`)
      .reply(202, {
        id: 'LIVEMOUNT_HYPERV_SNAPSHOT_e4742be5-bbe0-4886-840a-7531a3460025_c3106534-6c97-4b60-a016-e723cb20ef68:::0',
        status: 'QUEUED',
        progress: 0,
        startTime: '2024-05-03T09:14:43.048Z',
        links: [
          {
            href: 'https://10.0.35.180/api/internal/hyperv/vm/request',
            rel: 'self',
          },
        ],
      });

    render(
      <MockedProviders>
        <Form
          initialValues={{
            ...initialMockEmptyValues,
            ...{selectedHostId: 'mockHostId'},
          }}
        >
          <HyperVInstantRecoveryButton
            closeModal={() => {}}
            snapshotId={mockSnapshotId}
            snappable={{name: 'mockName', id: 'mockSnappableId'}}
          />
        </Form>
      </MockedProviders>,
    );

    const recoverButton = await screen.findByRole('button', {
      name: TID.INVENTORY.HYPERV.RECOVERY_WIZARD.RECOVER_BUTTON,
    });

    expect(recoverButton).toBeEnabled();

    await userEvent.click(recoverButton);

    await waitFor(() => {
      expect(mockAxios.history.post.length).toBe(1);
    });

    expect(mockAxios.history.post[0].data).toMatchInlineSnapshot(
      `"{\\"hostId\\":\\"mockHostId\\",\\"vmName\\":\\"mockName\\"}"`,
    );

    // check for notification
    const toast = await screen.findByRole('alert');

    expect(toast).toHaveTextContent(
      TID.INVENTORY.HYPERV.RECOVERY_WIZARD.SELECT_RECOVERY_OPTION_STEP.OPTIONS
        .INSTANT_RECOVER.SUCCESS_MUTATION,
    );
  });
  ```